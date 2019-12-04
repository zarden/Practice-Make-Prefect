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

	//���������ź�
	sigset_t set, old;
	sigemptyset(&set);//����źż���
	sigemptyset(&old);

	//sigaddset(int signum, sigset_t *set)��ָ���ź���ӵ�����
	sigfillset(&set);//�����е��źŶ���ӵ�set������
	sigprocmask(SIG_BLOCK, &set, &old);//���������ź�

	printf("press enter to continue\n");
	getchar();//�ڰ��»س�֮ǰ������������

	sigprocmask(SIG_UNBLOCK, &set, NULL);//�������
	return 0;
}
