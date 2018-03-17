//******** projectOS.c ***************
// Author: Murtuza Quaizar
// Purpose: Establish a simple Operating System for a 8 bit Micro.  
// WARNING: This module will Disables Global Interrupts when accessing semaphore;
//          The justification is to prevent a situation where function is 
//          blocked but its semaphore is > 1, or where the function is not 
//          blocked but semaphore is <1.  In either case, this will lock up
//          the entire program.  Those two situations will come about if  
//          setting the semaphore, and blocking the function (thread) is 
//          interrupted by an interrupt routine that also makes calls to 
//          OS_Signal.

#include <stdint.h>
#include "os.h"
#include <xc.h>

#define NUMTHREADS  4  // maximum number of threads

struct tcb{
  void (*func) (void); // pointer to function
  struct tcb *next;    // linked-list pointer
  int8_t *blocked;	   //pointer to blocked resource;
};

typedef struct tcb tcbType;

tcbType tcbs[NUMTHREADS];
tcbType *RunPt;


//******** OS_AddThreads ***************
// Add (4) main threads to the scheduler
// Inputs: function pointers to void/void main threads
// Outputs: nothing;
// This function will only be called once during startup, before while(1){}
// It strings together all the functions in a tail chain;
void OS_AddThreads( void(*func1)(void), 
                        void(*func2)(void),
                        void(*func3)(void),
                        void(*func4)(void))
{
    tcbs[0].func = func1;
    tcbs[1].func = func2;
    tcbs[2].func = func3;
    tcbs[3].func = func4;
    
    tcbs[0].next = &tcbs[1]; // 0 points to 1
    tcbs[1].next = &tcbs[2]; // 1 points to 2
    tcbs[2].next = &tcbs[3]; // 2 points to 3
    tcbs[3].next = &tcbs[0]; // 3 points to 0
    
    tcbs[0].blocked = 0;
    tcbs[1].blocked = 0;
    tcbs[2].blocked = 0;
    tcbs[3].blocked = 0;
    
    RunPt = &tcbs[0]; 
}

//******** OS_Launch ***************
// Starts the very first function;
// Afterwards, scheduler will call the remaining functions.
void OS_Launch(void)
{
    RunPt->func();
}

//******** OS_Scheduler ***************
// This will be the only function in the main while{} code
// This runs each thread in a cooperative tail chain.
// If thread is blocked, will skip to the next thread.
// If all threads are blocked, will then send the processor to sleep;
// Thread will be blocked from running if OS_Pass{} returns a (0) a fail; 
// Interrupt will be the only event that will wake the processor to sleep, 
// and resume the OS_Scheduler.
void OS_Scheduler(void)
{
    tcbType *PrvRunPt;  
    uint8_t sleep = 0;
    
    PrvRunPt = RunPt;        //save previous run pointer;
    RunPt = RunPt->next;     //get the next run pointer;
    
    while(RunPt->blocked)    
    {
        RunPt = RunPt->next;   //skip if blocked;
        
        if (RunPt == PrvRunPt)  //everyone is blocked;
        {
            if (RunPt->blocked) //check if the first element was also blocked;
            {
                sleep = 1;
            }
            break;
        }
    }
    
    if (!sleep)
        RunPt->func();  //run next function;
    else
    {
        //SLEEP();       //go to sleep;
    }

    
    
}

// ******** OS_Wait ************
// Decrement semaphore and block if less than zero
// Inputs:  pointer to a counting semaphore
// Outputs: 0 if thread is allowed to proceed;
//          1 if waiting for a semaphore;
uint8_t OS_Wait(int8_t *semaPt)
{
    uint8_t ret;
       
    if (*semaPt > 0)
    {
       (*semaPt) = 0;
        ret = 0;
    }
    else
    {
        RunPt->blocked = semaPt;
        (*semaPt) = -1;  
        ret = 1;
    }
       
    return(ret);
	
}

// ******** OS_Signal ************
// set semaphore
//
// Will loop through all the functions (threads) to see who has been blocked
// if we loop through and no one was blocked, we break out;
//
// wakeup blocked thread if appropriate
// Inputs:  pointer to a counting semaphore
// Outputs: none
void OS_Signal(int8_t *semaPt)
{
	tcbType *pt;
    tcbType *PrvPt;  
 
        
	//if(*semaPt < 0)
	//{
        
        PrvPt = RunPt;
		
        pt = RunPt->next;  //search for thread blocked on this semaphore;
           
		while(!(pt->blocked == semaPt))
		{
            //skip if this is not the blocking semaPt;
            
			pt= pt->next; 
            
            if (pt == PrvPt)
            {
                if(!(pt->blocked == semaPt))
                {
                    //no body has been blocked, break out;
                    break;
                }
            }
		}
		pt->blocked = 0;  //wakeup this thread;
	//}
    
    *semaPt = 1;
    
       
    return;

}

// ******** OS_Block ************
// Force thread/ to be blocked on semaphore; 
// Prevents double entry on the same function;
// Inputs:  pointer to a counting semaphore
// Outputs: ~
void OS_Block(int8_t *semaPt)
{
            
    (*semaPt) = -1;   
    RunPt->blocked = semaPt;
    

}