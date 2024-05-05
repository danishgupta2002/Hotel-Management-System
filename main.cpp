#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Hotel
{
    private:
        struct Node
        {
            int id, date;
            string name, roomType;
            Node* next;
        };

    public:
        Node* head=NULL;
        void insert();
        void menu();
        void update();
        void search();
        void del();
        void sort();
        void show();
};

void Hotel::menu()
{
    p:

    int choice;
    cout<<"\n";
    cout<<"\tWelcome To Hotel Management System Application\n"<<endl;
    cout<<"\n\t______Hotel Management System______";
    cout<<"\n\nS.No    Functions             Description "<<endl;
    cout<<"\n1\tAllocate Room\t\t\tAssign New Room";
    cout <<"\n2\tSearch Room\t\t\tSearch Room with RoomID";
    cout <<"\n3\tUpdate Room\t\t\tUpdate Room Record";
    cout <<"\n4\tDelete Room\t\t\tDelete Room with RoomID";
    cout <<"\n5\tShow Room Records\t\t\tShow Room Records that we added";
    cout<<"\n6\tExit"<<endl;

    cout<<"Enter Your Choice: "<<endl;
    cin>>choice;

    switch(choice)
    {
        case 1: 
            insert();
            menu();

        case 2:
            search();
            menu();

        case 3:
            update();
            menu();

        case 4:
            del();
            menu();

        case 5:
            sort();
            show();
            menu();
        

        case 6:
            exit(0);

            default:
            cout<<"Invalid";
    }
}


void Hotel::insert()
{
    cout<<"\n\t________Hotel Management System______"<<endl;
    Node* new_node= new Node;
    cout<<"\nEnter Room Id: "<<endl;
    cin >>new_node->id;
    cout<<"\nEnter Customer Name: "<<endl;
    cin>>new_node->name;
    cout<<"\nEnter Allocated Date: "<<endl;
    cin>>new_node->date;
    cout<<"\nEnter Room Type(single/double/twin): "<<endl;
    cin>>new_node->roomType;

    if(head==NULL)
    {
        head= new_node;
    }
    else
    {
        Node* ptr=head;
        while(ptr->next !=NULL)
        {
            ptr= ptr->next;
        }
        ptr->next= new_node;
    }
    cout<<"\n\n\t\t New Room Inserted!\n"<<endl;
}


void Hotel::search()
{
    cout <<"\n\t________Hotel Management System______" <<endl;
    int t_id;
    if (head == NULL)
    {
        cout<<"\n\nList is empty.";
    }
    else
    {
        cout<<"\n\nEnter Room ID: ";
        cin>>t_id;
        Node *ptr = head;
        while(ptr!=NULL)
        {
            if(t_id== ptr->id)
            {
                cout<<"\n\nRoom ID"<<ptr->id;
                cout<<"\n\nCustomer Name"<<ptr->name;
                cout<<"\n\nRoom Allocated Date"<<ptr->date;
                cout<<"\n\nRoom Type"<<ptr->roomType;
            }
            ptr=ptr->next;
        }
    }
}


void Hotel::update()
{
    cout <<"\n\t________Hotel Management System______" << endl;
    int t_id;
    if (head == NULL)
    {
        cout <<"\n\nList is empty.";
    }
    else
    {
       cout<<"\n\nRoom ID";
       cin>>t_id;
       Node* ptr=head;
       while(ptr!=NULL)
       {
            if(t_id==ptr->id)
            {
                cout<<"\n\nRoom ID"; 
                cin>>ptr->id;

                cout<<"\n\nCustomer Name";
                cin>>ptr->name;

                cout<<"\n\nAllocated Date";
                cin>>ptr->date;

                cout<<"\n\nRoom Type";
                cin>>ptr->roomType;

                cout<<"\n\n\t\t Updated Record Successfully!\n";
            }

            ptr= ptr->next;
       } 
    }
}


void Hotel::del()
{
    cout<<"\n\t________Hotel Management System______"<<endl;
    int t_id;
    if(head == NULL)
    {
        cout<<"\n\nList is empty.";
    }
    else
    {
        cout<<"\n\nRoom ID";
        cin>>t_id;
        if(t_id==head->id)
        {
            Node* ptr= head;
            head= head->next;
            delete ptr;
            cout<<"Deleted Room Record Successfully!\n";
        }
        else
        {
            Node* pre=head;
            Node* ptr= head;
            while(ptr!=NULL)
            {
                if(t_id==ptr->id)
                {
                    pre->next= ptr->next;
                    delete ptr;
                cout << "Deleted Room Record Successfully!\n";
                break;
                }
                pre=ptr;
                ptr=ptr->next;
            }
        }
    }
}


void Hotel::show()
{
    Node* ptr=head;
    while(ptr!=NULL)
    {
        cout<<"\n\nRoomID"<<ptr->id;

        cout<<"\n\nCustomer Name"<<ptr->name;

        cout<<"\n\nAllocated Date"<<ptr->date;

        cout<<"\n\nRoom Type"<<ptr->roomType;

        ptr=ptr->next;
    }
}


void Hotel::sort()
{
    if(head==NULL)
    {
        cout<<"\n\nList is Empty";
        menu();
    }

    int count=0,t_date, t_id;
    string t_name, t_roomType;
    Node* ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }

    for(int i=1; i<=count; i++)
    {
        Node* ptr= head;
        for(int j=1; j<count; j++)
        {
            if(ptr->id > ptr->next->id)
            {
                t_id=ptr->id;
                t_name=ptr->name;
                t_date=ptr->date;
                t_roomType=ptr->roomType;

                //Save Date Into Current Node
                ptr->id=ptr->next->id;
                ptr->name=ptr->next->name;
                ptr->date=ptr->next->date;
                ptr->roomType=ptr->next->roomType;

                //Save data into Next node
                ptr->next->id=t_id;
                ptr->next->name=t_name;
                ptr->next->date=t_date;
                ptr->next->roomType=t_roomType;
            }
        }
    }
}

int main()
{
    Hotel h;
    h.menu();
}