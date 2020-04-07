#include <iostream>
#include <string>
#include <vector>
using namespace std;

class list_node {
public:
    list_node() = default;
    list_node(int v, list_node *n) : val(v), next(n) {}

    int val = 0;
    list_node *next = nullptr;
};

list_node * get_list(void);
void display_list(const list_node *head);
void destroy_list(list_node *head);
list_node * delete_node(list_node *head, int val);


int main() {
    cout << "please enter some number as node\n"
        << "eg:\n"
        << "1, 3, 5, 9 ..." << endl;

    list_node *head = get_list();
    cout << "you entered: " << endl;
    display_list(head);

    cout << "\nplease enter the val you  want to delete: " << endl;
    int val = 0;
    cin >> val;
    head = delete_node(head, val);
    cout << "after delete " << val << "from list: " << endl;
    display_list(head);

    destroy_list(head);

    return 0;
}
list_node * get_list(void) {
    list_node tmp;
    list_node *ret = &tmp;
    list_node *p = &tmp;
    string num;

    while(cin >> num) {
        if (num == ",") continue;
        if (num == "#") break;
        int val = atoi(num.c_str());
        p->next = new list_node(val, nullptr);
        p = p->next;
    }

    return ret->next;
}

void display_list(const list_node *head) {
    if (head == nullptr) return;
    while (head) {
        cout << head->val << "\t";
        head = head->next;
    }
    cout << endl;
}

void destroy_list(list_node *head) {
    list_node *p = head;
    while(head) {
        p = head;
        head = head->next;
        delete p;
    }
}

list_node * delete_node(list_node *head, int val) {

    if (head == nullptr) return nullptr;

    list_node *pre = head;
    list_node *cur = pre->next;
    if (pre->val == val) {
        delete pre;
        return cur;
    }
    while (cur) {
        if (cur->val == val) {
            pre->next = cur->next;
            delete cur;
        }
        pre = cur;
        cur = cur->next;
    }

    return head;
}
