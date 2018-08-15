#include <stdio.h>
#include <stdlib.h>

/**
 * this code is referenced from 'https://swexpertacademy.com/main/userpage/home/userHome.do?userId=AWHghhbKKdIDFAWj'
 * for studying.
 *
 * using stl list causes segmenttation fault.
 */

typedef struct list
{
    int data;
    struct list * link;
}ListNode;

ListNode * head, * tail;

void Init_Node()
{
    head = tail = NULL;
}

ListNode * Creat_Node(void)
{
    int data;
    ListNode * temp = (ListNode *)malloc(sizeof(ListNode));
    scanf("%d", &data);
    temp->data = data;
    temp->link = NULL;
    return temp;
}
void Display_Node()
{
    int i;
    ListNode * temp = head;
    for (i = 0; i< 10; i++)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void Add_Node(int num_node)
{
    int i, data;
    ListNode * temp;

    for (i = 0; i < num_node; i++)
    {
        temp = Creat_Node();
        if (tail == NULL && head == NULL)
            head = tail = temp;

        else
        {
            tail->link = temp;
            tail = temp;
        }
    }
}

void Insert_Node(int before_position, int num_node)
{
    int i, data;
    ListNode * before=head, *temp;

    for (i = 1; i < before_position; i++)
        before = before->link;

    if (before_position == 0) before = NULL;

    for (i = 0; i < num_node; i++)
    {
        temp = Creat_Node();
        if(before == NULL )
        {
            temp->link = head;
            before = head = temp;
        }
        else
        {
            temp->link = before->link;
            before->link = temp;
            before = temp;
        }
    }
}

void Delete_Node(int before_position, int num_node)
{
    int i;
    ListNode *target, *before = head;

    for (i = 1; i < before_position; i++)
        before = before->link;

    if (before_position == 0) before = NULL;

    for (i = 0; i < num_node; i++)
    {
        if (before == NULL)
        {
            target = head;
            head = head->link;
        }
        else
        {
            target = before->link;
            before->link = target->link;
        }
        free(target);
    }
}


int main(void)
{
    int i, t, N, position, num;
    char command;
    for (t = 1; t <= 10; t++)
    {
        Init_Node();
        scanf("%d", &N);
        Add_Node(N);

        scanf("%d", &N);
        for (i = 0; i < N; i++)
        {
            scanf(" %c ", &command);
            switch (command)
            {
                case 'I':
                    scanf("%d %d", &position, &num);
                    Insert_Node(position, num);
                    break;
                case 'A':
                    scanf("%d", &num);
                    Add_Node(num);
                    break;
                case 'D':
                    scanf("%d %d", &position, &num);
                    Delete_Node(position, num);
                    break;
            }
        }
        printf("#%d ", t);
        Display_Node();
    }
    return 0;
}