#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sigcb(int signum)
{
	printf("recv a signal:%d\n", signum);
}
int main()
{
	signal(2, sigcb);
	signal(40, sigcb);

	//阻塞所有信号
	sigset_t set, old;
	sigemptyset(&set);//清空信号集合
	sigemptyset(&old);

	//sigaddset(int signum, sigset_t *set)将指定信号添加到集合
	sigfillset(&set);//将所有的信号都添加到set集合中
	sigprocmask(SIG_BLOCK, &set, &old);//阻塞所有信号

	printf("press enter to continue\n");
	getchar();//在按下回车之前，程序卡在这里

	sigprocmask(SIG_UNBLOCK, &set, NULL);//解除阻塞
	return 0;
}
