extern int everybody_print(char* msg,int msg_len);
static char* msg = "ATAM!\n";
int len = 6;
static int var = 0;
int c_turn() {
	everybody_print(msg,len);
	return 0;
}
