struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *partition(struct Node *head, int x)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    vector<int> a;
    vector<int> b;
    vector<int> c;

    Node *cur = head;
    while (cur)
    {
        if (cur->data < x)
        {
            a.push_back(cur->data);
        }

        if (cur->data == x)
        {
            b.push_back(cur->data);
        }
        else
        {
            c.push_back(cur->data);
        }
        cur = cur->next;
    }

    int n = a.size();
    int m = b.size();
    int o = c.size();

    int i = 0, j = 0, k = 0;

    Node *cur1 = head;

    while (cur1)
    {
        if (i < n and cur1)
        {
            cur1->data = a[i];
            i++;
        }
        else if (j < m and cur1)
        {
            cur1->data = b[j];
            j++;
        }

        else if (k < o and cur1)
        {
            cur1->data = b[j];
            k++;
        }
        cur1 = cur1->next;
    }

    return head;
}