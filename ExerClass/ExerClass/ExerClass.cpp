#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

enum 
{
	SPADES,//����?��ö�ٸ�ֵĬ�ϴ�0��ʼ
	HEARTS,//����?
	CLUBS,//÷��?
	DIAMONDS,//����?
	JOKEER//��
};

//ȫ�ֱ���g_ �ֲ���̬����s_��Ա����m_

class Poker
{
	char m_type;
	int m_point;
public:
	Poker() :
		m_type(0),
		m_point(0)
	{
	}
	Poker(char type, int point) :
		m_type(type),
		m_point(point)
	{
	}

	void makePoker(char type, int point)
	{
		m_type = type;
		m_point = point;

		if (m_type == JOKEER)
		{
			m_point += 13;
		}
	}

	void outputPoker()
	{
		char *type[5] = { "����", "����", "÷��", "����", "" };
		char *point[16] = { "", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "С��", "����" };

		printf("%s%s", type[m_type], point[m_point]);

	}

	bool cmppoker(Poker tmp)
	{
		return(m_point<tmp.m_point) ||
			(m_point == tmp.m_point && m_type>tmp.m_type);
	}

	bool isEff()//���ɵ����Ƿ���Ч
	{
		if (m_type == JOKEER && (m_point == 14 || m_point == 15))
		{
			return true;
		}

		if ((unsigned char)m_type > 3 ||
			(unsigned int)m_point - 1 > 13)
		{
			return false;
		}
		return true;
	}
};

class Player{
	Poker m_HandCard[18];
	int m_size;
public:
	Player() :m_size(0){}

	void getCard(Poker newCard)
	{
		int i;
		for ( i = m_size; i>0 && m_HandCard[i-1].cmppoker(newCard); i--)
		{
			m_HandCard[i] = m_HandCard[i - 1];
		}

		m_HandCard[i] = newCard;
		m_size++;
	}

	void showCard()
	{
		for (auto &i : m_HandCard)
		{
			i.outputPoker();
			putchar(' ');
		}
		putchar('\n');
	}
};

void pokerTest()
{
	srand((unsigned)time(NULL));
	Player p1;
	Poker tmp(0, 3);

	int i;
	for ( i = 0; i < 18; i++)
	{
		tmp.makePoker(rand() % 4, rand() % 13 + 1);
		p1.getCard(tmp);
	}
	p1.showCard();
}

int randnum(Poker * cardHeap)
{
	int tmp = rand() % 54;
	while (1)
	{
		if (cardHeap[tmp].isEff())
		{
			return tmp;
		}
		else
		{
			tmp++;
			if (tmp==54)
			{
				tmp = 0;
			}
		}
	}
}

int main1()
{
	Poker tmp[54];
	int j = 0;
	Player ayi;
	Player laoye;
	Player miao17;

	for (auto &i:tmp)
	{
		i.makePoker(j / 13, j % 13 + 1);
		j++;
	}

	srand((unsigned)time(NULL));

	int declard;

	int i;
	for ( i = 0; i < 18; i++)
	{
		declard = randnum(tmp);
		ayi.getCard(tmp[declard]);
		tmp[declard].makePoker(-1, -1);

		declard = randnum(tmp);
		laoye.getCard(tmp[declard]);
		tmp[declard].makePoker(-1, -1);

		declard = randnum(tmp);
		miao17.getCard(tmp[declard]);
		tmp[declard].makePoker(-1, -1);
	}

	ayi.showCard();
	laoye.showCard();
	miao17.showCard();

	system("pause");
	return 0;
}