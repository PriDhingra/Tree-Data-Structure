#include<iostream>
#include<queue>
using namespace std;

class node {
    public: 
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {

    cout << "Enter the data : "<<endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1) {
        return NULL;
    }

    cout<<"Enter the data to be entered on left of : " << data << endl;
    root -> left = buildTree(root -> left);
    cout<<"Enter the data to be entered on right of : " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout<< endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout<<temp -> data<<" ";
            if(temp -> left) {
                q.push(temp -> left);
            }

            if(temp -> right) {
                q.push(temp -> right);
            }
        }
    }
}

void givenLevelTraverse(node* root, int level) {
    
    if(root == NULL) {
        return;
    }
    if(level == 1) {
        cout<<root -> data<<" ";
    }
    if(level > 1) {
        givenLevelTraverse(root -> left, level -1);
        givenLevelTraverse(root -> right, level -1);
    }
}


int main() {
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    root = buildTree(root);

    levelOrderTraversal(root);

    givenLevelTraverse(root, 2);

    return 0;
}
