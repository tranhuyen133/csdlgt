#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Danh sách kề : ý tưởng mỗi đỉnh sẽ là 1 danh sách liên kết sách với các đỉnh khác
// Tạo cấu trúc 1 node
typedef struct Node {
    int data;
    struct Node* next;
}Node;
//Viết hàm tạo node
NODE* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
};
//Tạo mảng chứa danh sách các con trỏ trỏ tới từng đỉnh
Node* createAdjacency(int U,int V) {
    //Tạo 1 nốt mới,thêm vào đầu
    Node* newNode = createNode(U);
    //Đi liên kết với phan tử ban đầu
    newNode->next = createNode(U);
    newNode = createNode(U);//NewNode lúc này sẽ là phần tử đầu
    newNode = createNode(V);
    newNode->next = createNode(V);//Liên kết voới phần tu ban đầu
    newNode = createNode(V);//newNode bây giờ sẽ thành phần tử đầu tiên

}
Node* adjacency[4];
int main() {
    //Khởi tạo các giá trị trong mảng về NULL
    for(int i=0;i<4;i++) {
        adjacency[i] = NULL;

    }
    addAjacency(0,1);
    printf();
}
