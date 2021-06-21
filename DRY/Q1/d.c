extern int var;
extern int everybody_print(char* msg,int msg_len);
extern int c_turn();
static char* msg = "love ";
int msg_len = 5;

int d_turn(){
	var = 3;
	everybody_print(msg,msg_len);
	return c_turn();
}