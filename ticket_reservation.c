/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct Ticket
{
    int ticket_no;
    struct Ticket *link;
};
struct Ticket *rear=NULL, *front =NULL;
void bookTicket(int ticket_no)
{
    struct Ticket *newnode=(struct Ticket *)malloc(sizeof(struct Ticket));
    if(newnode==NULL)
    {
        printf("Memory allocation not possible\n");
        exit(0);
    }
    newnode->ticket_no=ticket_no;
    newnode->link=NULL;
    if(rear==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->link=newnode;
        rear=newnode;
    }
    printf("Ticket %d booked successfully\n", ticket_no);
}
void cancelTicket()
{
    if(front==NULL)
    {
        printf("No tickets are there to cancel\n");
        return ;
    }
    struct Ticket *current=front;
    printf("Ticket %d canceled successfully\n", current->ticket_no);
    front=front->link;
    free(current);
}
void displayTicket()
{
    struct Ticket *current=front;
    if(front==NULL)
    {
        printf("No tickets booked\n");
    }
    printf("---Waiting list---\n");
    while(current!=NULL)
    {
        printf("Ticket number: %d\n", current->ticket_no);
        current=current->link;
    }
}
int main()
{
    int choice, ticket_no;
    printf("\n---Queue Based Ticket Reservation System---\n");
    do
    {
        printf("\nMenu\n1. Book Tickets\n2. Cancel Tickets\n3. Display Tickets\n4. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:{
                printf("Enter the ticket nmuber to book:");
                scanf("%d", &ticket_no);
                bookTicket(ticket_no);
            }
            break;
            case 2:cancelTicket();
            break;
            case 3:displayTicket();
            break;
            case 4:printf("Exiting program\n");
            break;
            default:printf("Invalid choice\n");
        }
    }while(choice!=4);

    return 0;
}
