#ifndef stateMachine_included
#define stateMachine_included

extern unsigned char state;
extern unsigned char substate;
extern unsigned char history;

void state_advance();
void substate_advance();

#endif // included
