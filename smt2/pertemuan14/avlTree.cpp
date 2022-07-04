#include <iostream>
#include <limits>
using namespace std;

struct Node
{
    int data;
    Node *kiri;
    Node *kanan;
};

Node *pohon = NULL;

int inputInt()
{
    int x = 0;
    // jika input mengalami kegagalan ulangi input
    while (!(cin >> x))
    {
        cin.clear(); // menghilangkan flag error
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << "Input bukan integer. coba lagi : ";
    }
    return x;
}
void tambah(Node **root, int newData)
{
    // jika root masih kosong
    if ((*root) == NULL)
    {
        Node *baru;
        baru = new Node;
        baru->data = newData;
        baru->kiri = NULL;
        baru->kanan = NULL;
        (*root) = baru;
        (*root)->kiri = NULL;
        (*root)->kanan = NULL;
        printf("Data Berhasil Ditambah!\n");
    }else if(newData <= (*root)->data){
        tambah(&(*root)->kiri, newData);
    }else if(newData >= (*root)->data){
        tambah(&(*root)->kanan, newData);
    }
}

void preOrder(Node *root){
    if (root != NULL)
    {
        if (root->data)
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
        if (root->data)
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
        if (root->data)
        {
            printf("%", root->data);
        }
    }
}

void pilihan(){
    cout<<"1. Tambah Data\n";
    cout<<"2. Preorder\n";
    cout<<"3. Inorder\n";
    cout<<"4. Postorder\n\n";
}
int main()
{
    int pilih;

    pilihan();
    do
    {
        pilih = inputInt();
        switch (pilih)
        {
        case 1: tambah(&pohon, inputInt());
            break;
        case 2: preOrder(pohon);
            break;
        case 3: inOrder(pohon);
            break;
        case 4: postOrder(pohon);
            break;
        
        default:
            break;
        }
    } while (pilih != 9);
    
    return 0;
}