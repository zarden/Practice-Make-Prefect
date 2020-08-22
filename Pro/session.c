#include"session.h"

void begin_session(session_t *sess)
{
	
	priv_sock_init(sess);

	pid_t pid = fork();
	if(pid == -1)
		ERR_EXIT("fork");
	if(pid == 0)
	{
		//ftp 
		priv_sock_set_child_context(sess);
		handle_child(sess);
	}
	else
	{
		//nobody 
		priv_sock_set_parent_context(sess);
		handle_parent(sess);
	}
}