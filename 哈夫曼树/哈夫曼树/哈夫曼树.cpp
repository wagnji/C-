// ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include <iostream>

using namespace std;

 

//����ַ��������鳤��

#define MAXCODELEN 100

//���������ڵ�ṹ���������

#define MAXHAFF 100

//������������ṹ������ĸ���

#define MAXCODE 100

#define MAXWEIGHT  10000;

 

 

typedef struct Haffman

{

    //Ȩ��

    int weight;

    //�ַ�

    char ch;

    //���ڵ�

    int parent;

    //����ӽڵ�

    int leftChild;

    //�Ҷ��ӽڵ�

    int rightChild;

}HaffmaNode;

 

typedef struct Code

{

    //�ַ��Ĺ���������Ĵ洢

    int code[MAXCODELEN];

    //���ĸ�λ�ÿ�ʼ

    int start;

}HaffmaCode;

 

HaffmaNode haffman[MAXHAFF];

HaffmaCode code[MAXCODE];

 

void buildHaffman(int all)

{

    //�������ڵ�ĳ�ʼ��֮ǰ�Ĺ���, weightΪ0,parent,leftChile,rightChile��Ϊ-1

    for (int i = 0; i < all * 2 - 1; ++i)

    {

        haffman[i].weight = 0;

        haffman[i].parent = -1;

        haffman[i].leftChild = -1;

        haffman[i].rightChild = -1;

    }

    std::cout << "��������Ҫ������������ַ���Ȩ�ش�С" << std::endl;

    for (int i = 0; i < all; i++)

    {

        std::cout << "��ֱ�����ڸ�" << i << "�������ַ���Ȩ��" << std::endl;

        std::cin >> haffman[i].ch;

        std::cin >> haffman[i].weight;

    }

    //ÿ���ҳ���С��Ȩ�صĽڵ�,�����µĽڵ�,��Ҫall - 1 �κϲ�

    int x1, x2, w1, w2;

    for (int i = 0; i < all - 1; ++i)

    {

        x1 = x2 = -1;

        w1 = w2 = MAXWEIGHT;

        //ע������ÿ����all + i���������

        for (int j = 0; j < all + i; ++j)

        {

            //�õ���СȨ�صĽڵ�

            if (haffman[j].parent == -1 && haffman[j].weight < w1)

            {

                //���ÿ����С�ĸ����ˣ���ô��Ҫ���ϴ���С�ĸ��ڶ�����С��

                w2 = w1;

                x2 = x1;



                x1 = j;

                w1 = haffman[j].weight;

            }

            //������else if������if,����Ϊ����ÿ��ֻѡ1���Ϳ����ˡ�

            else if(haffman[j].parent == -1 && haffman[j].weight < w2)

            {

                x2 = j;

                w2 = haffman[j].weight;

            }

        }

        //ÿ���ҵ���С�������ڵ��Ҫ�ǵúϲ���һ���µĽڵ�

        haffman[all + i].leftChild = x1;

        haffman[all + i].rightChild = x2;

        haffman[all + i].weight = w1 + w2;

        haffman[x1].parent = all + i;

        haffman[x2].parent = all + i;

        std::cout << "x1 is" << x1 <<" x1 parent is"<<haffman[x1].parent<< " x2 is" << x2 <<" x2 parent is "<< haffman[x2].parent<< " new Node is " << all + i << "new weight is" << haffman[all + i].weight << std::endl;

    }

}



//��ӡÿ���ַ��Ĺ���������

void printCode(int all)

{

    //���浱ǰҶ�ӽڵ���ַ�����

    HaffmaCode hCode;

    //��ǰ���ڵ�

    int curParent;

    //�±��Ҷ�ӽڵ�ı��

    int c;

    //�������ܴ���

    for (int i = 0; i < all; ++i)

    {

        hCode.start = all - 1;

        c = i;

        curParent = haffman[i].parent;

        //�����������Ǹ��ڵ㲻����-1

        while (curParent != -1)

        {

            //�������õ����ڵ㣬Ȼ���ж���ڵ��Ƿ�Ϊ��ǰֵ�������ȡ�ڵ�0

            //����ȡ�ڵ�1,�����c��䶯�����Բ�Ҫ��i��ʾ��������c���浱ǰ����i

            if (haffman[curParent].leftChild == c)

            {

                hCode.code[hCode.start] = 0;

                std::cout << "hCode.code[" << hCode.start << "] = 0" << std::endl;

            }

            else

            {

                hCode.code[hCode.start] = 1;

                std::cout << "hCode.code[" << hCode.start << "] = 1" << std::endl;

            }

            hCode.start--;

            c = curParent;

            curParent = haffman[c].parent;

        }

        //�ѵ�ǰ��Ҷ�ӽڵ���Ϣ���浽����ṹ������

        for (int j = hCode.start + 1; j < all; ++j)

        {

            code[i].code[j] = hCode.code[j];

        }

        code[i].start = hCode.start;

    }



}



int main()

{

    std::cout << "�������ж��ٸ��������ַ�" << std::endl;

    int all = 0;

    std::cin >> all;

    if (all <= 0)

    {

        std::cout << "������ĸ�������" << std::endl;

        return -1;

    }

    buildHaffman(all);

    printCode(all);

    for (int i = 0; i < all; ++i)

    {

        std::cout << haffman[i].ch << ": Haffman Code is:";

        for (int j = code[i].start + 1; j < all; ++j)

        {

            std::cout << code[i].code[j];

        }

        std::cout << std::endl;

    }

    return 0;

}



