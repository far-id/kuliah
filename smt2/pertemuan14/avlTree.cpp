#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *kiri;
    Node *kanan;
};

Node *pohon = NULL;

void tambah(Node **root, int newData)
{
    // jika root masih kosong
    if ((*root) == NULL)
    {
        Node *baru;
        root = new Node;
        baru->data = newData;
        baru->kiri = NULL;
        baru->kanan = NULL;
        (*root) = baru;
        (*root)->kiri = NULL;
        (*root)->kanan = NULL;
        printf("Data Berhasil Ditambah!");
    }else if(newData <= (*root)->data){
        tambah(&(*root)->kiri, newData);
    }else if(newData >= (*root)->data){
        tambah(&(*root)->kanan, newData);
    }
}

void preOrder(Node *root){
    if (root != NULL)
    {
        if (root->data != NULL)
        {
            printf("%d", root->data);
        }
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Node *root){
    if (root != NULL)
    {
        inOrder(root->kiri);
        if (root->data != NULL)
        {
            printf("%d", root->data);
        }
        inOrder(root->kanan);
    }
}

void postOrder(Node *root){
    if (root != NULL)
    {
        postOrder(root->kiri);
        postOrder(root->kanan);
        if (root->data != NULL)
        {
            printf("%", root->data);
        }
    }
}

void pilihan(){
    cout<<"1. Tambah Data\n";
    cout<<"2. Preorder\n";
    cout<<"3. Inorder\n";
    cout
}
int main()
{
    int pilih;

    do
    {
        pilihan();
    } while (pilih != 9);
    
    return 0;
}