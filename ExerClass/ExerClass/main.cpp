#include<iostream>
#include<cstdio>
using namespace std;

enum
{
	SPADES,//����?��ö�ٸ�ֵĬ�ϴ�0��ʼ
	HEARTS,//����?
	CLUBS,//÷��?
	DIAMONDS,//����?
	JOKEER//��
};

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

	Poker(const Poker &p)
	{
		m_point = p.m_point;
		m_type = p.m_type;
	}
	~Poker()
	{
		cout << "�ѱ�����" << endl;
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
		for (i = m_size; i>0 && m_HandCard[i - 1].cmppoker(newCard); i--)
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

int main()
{
	Poker card(0, 3);
	Poker card2 = card;
	int i(6);

	card.outputPoker();
	card2.outputPoker();
	cout << i << endl;
	system("pause");
	return 0;
}