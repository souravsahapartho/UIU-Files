#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int coeff;
    int expo;
    Node *next;

    Node(int coeff, int expo) : coeff(coeff), expo(expo), next(NULL) {}
};

void parse_and_initialize(string str, Node *&head, Node *&tail)
{
    int n = str.length();

    for (int i = 0; i < n;)
    {
        int coeff = 0, expo = 0, coef_sign = 1, expo_sign = 1;

        if (str[i] == '+' || str[i] == '-')
        {
            coef_sign = (str[i] == '+') ? 1 : -1;
            i++;
        }

        if (isdigit(str[i]))
        {
            while (i < n && isdigit(str[i]))
            {
                coeff = coeff * 10 + (str[i] - '0');
                i++;
            }
        }
        else
        {
            coeff = 1;
        }

        if (i < n && str[i] == 'x')
        {
            i++;
            if (i < n && str[i] == '^')
            {
                i++;
                if (str[i] == '+' || str[i] == '-')
                {
                    expo_sign = (str[i] == '+') ? 1 : -1;
                    i++;
                }
                while (i < n && isdigit(str[i]))
                {
                    expo = expo * 10 + (str[i] - '0');
                    i++;
                }
            }
            else
            {
                expo = 1;
            }
        }
        else
        {
            expo = 0;
        }

        coeff *= coef_sign;
        expo *= expo_sign;

        if (head == NULL)
        {
            head = tail = new Node(coeff, expo);
        }
        else
        {
            tail = tail->next = new Node(coeff, expo);
        }
    }
}

Node *addition(Node *head1, Node *head2)
{
    Node *result = NULL, *tail = NULL;

    while (head1 != NULL)
    {
        Node *temp = head2;
        bool added = false;

        while (temp != NULL)
        {
            if (head1->expo == temp->expo)
            {
                added = true;
                if (result == NULL)
                {
                    tail = result = new Node(head1->coeff + temp->coeff, head1->expo);
                }
                else
                {
                    tail = tail->next = new Node(head1->coeff + temp->coeff, head1->expo);
                }
                break;
            }
            temp = temp->next;
        }

        if (!added)
        {
            if (result == NULL)
            {
                tail = result = new Node(head1->coeff, head1->expo);
            }
            else
            {
                tail = tail->next = new Node(head1->coeff, head1->expo);
            }
        }

        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        Node *temp = result;
        bool exists = false;

        while (temp != NULL)
        {
            if (head2->expo == temp->expo)
            {
                exists = true;
                break;
            }
            temp = temp->next;
        }

        if (!exists)
        {
            tail = tail->next = new Node(head2->coeff, head2->expo);
        }

        head2 = head2->next;
    }

    return result;
}

void display(Node *head)
{
    if (head == NULL)
    {
        cout << "0\n";
        return;
    }

    bool first = true;
    while (head != NULL)
    {
        int c = head->coeff, e = head->expo;
        if (first)
        {
            if (c < 0)
                cout << "-";
        }
        else
        {
            cout << (c < 0 ? " - " : " + ");
        }

        int absC = abs(c);
        if (e == 0)
        {
            cout << absC;
        }
        else
        {
            if (absC != 1)
                cout << absC;
            cout << "x";
            if (e != 1)
                cout << "^" << e;
        }
        first = false;
        head = head->next;
    }
    cout << "\n";
}

int main()
{
    string str1, str2;
    cout << "Enter Polynomial 1: ";
    cin >> str1;
    cout << "Enter Polynomial 2: ";
    cin >> str2;

    Node *head1 = NULL, *tail1 = NULL;
    Node *head2 = NULL, *tail2 = NULL;

    parse_and_initialize(str1, head1, tail1);
    parse_and_initialize(str2, head2, tail2);

    Node *result = addition(head1, head2);
    cout << "Resultant Polynomial: ";
    display(result);

    return 0;
}
