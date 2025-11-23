#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string id;
    Node *next;

    Node(string train_id)
    {
        id = train_id;
        next = NULL;
    }
};

class Traintrack
{
private:
    Node *head;

public:
    Traintrack()
    {
        head = NULL;
    }

    void add_train(string id)
    {
        Node *newNode = new Node(id);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void
    depart_train(string id)
    {
        if (!head)
        {
            return;
        }
        if (head->id == id)
        {
            Node *to_delete = head;
            head = head->next;
            delete to_delete;
            return;
        }

        Node *temp = head;
        while (temp->next && temp->next->id != id)
        {
            temp = temp->next;
        }
        if (temp->next)
        {
            Node *to_delete = temp->next;
            temp->next = temp->next->next;
            delete to_delete;
        }
    }

    void emergency_block(int pos)
    {
        if (!head || pos < 0)
        {
            return;
        }
        if (pos == 0)
        {
            Node *to_delete = head;
            head = head->next;
            delete to_delete;
            return;
        }

        Node *temp = head;
        for (int i = 0; temp != NULL && i < pos - 1; i++)
        {
            temp = temp->next;
        }
        if (temp != NULL && temp->next != NULL)
        {
            Node *to_delete = temp->next;
            temp->next = temp->next->next;
            delete to_delete;
        }
    }

    void display_tracks()
    {
        if (!head)
        {
            cout << "No trains on the track." << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->id;
                if (temp->next != NULL)
                {
                    cout << " -> ";
                }
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Traintrack track;
    int choice;

    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Add Train" << endl;
        cout << "2. Depart Train" << endl;
        cout << "3. Emergency Block" << endl;
        cout << "4. Display Tracks" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        if (choice == 1)
        {
            string id;
            cout << "Enter train ID to add: ";
            cin >> id;
            track.add_train(id);
        }

        else if (choice == 2)
        {
            string id;
            cout << "Enter train ID to depart: ";
            cin >> id;
            track.depart_train(id);
        }

        else if (choice == 3)
        {
            int pos;
            cout << "Enter position to block (0-based): ";
            cin >> pos;
            track.emergency_block(pos);
        }
        else if (choice == 4)
        {
            cout << "Current tracks: ";
            track.display_tracks();
        }
        else if (choice == 5)
        {
            cout << "Exiting system. Thank you!" << endl;
        }
        else
        {
            cout << "invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
