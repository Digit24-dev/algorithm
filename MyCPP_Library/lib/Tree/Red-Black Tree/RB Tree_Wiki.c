/*
 <레드-블랙 트리>

레드-블랙 트리는 자가 균형 이진 탐색 트리 (self-balancing binary search tree)로써,
연관 배열(연상, 결합형 배열, 맵, 사전) 등을 구현하는 데 쓰이는 자료구조이다. 
대칭형 이진 트리를 발전 시켜 만들었다.

O(long n)의 시간 복잡도로 삽입, 삭제, 검색을 할 수 있다.

 [용도와 장점]
자료의 삽입과 삭제, 검색에서 최악의 경우에도 일정한 실행 시간을 보장한다.
이는 실시간 처리와 같은 실행시간이 중요한 경우에 유용하게 쓰일 뿐만 아니라
일정한 실행 시간을 보장하는 또 다른 자료구조를 만드는 데에도 쓸모가 있다.

AVL 트리는 레드-블랙 트리보다 더 엄격하게 균형이 잡혀있기 때문에
삽입과 삭제를 할때 최악의 경우에는 더 많은 회전이 필요하다.

레드-블랙 트리는 함수형 프로그래밍에서 특히 유용한데, 함수형 프로그래밍에서
쓰이는 연관배열이나 집합(set) 등을 내부적으로 레드-블럭 트리로 구현해 놓은 경우가 많다.

 [특성]
레드-블랙 트리는 각 노드가 레드나 블랙인 색상 속성을 가지고 있는 이진 탐색 트리.
이진 탐색 트리가 가지고 있는 일반적인 조건에 다음과 같은 추가적인 조건을 만족해야
유효한 레드-블랙 트리가 된다.

1. 노드는 레드/블랙 중의 하나이다.
2. 루트 노드는 블랙이다.
3. 모든 리프 노드들은 블랙이다.
4. 레드 노드의 자식노드 양쪽은 언제나 모두 블랙이다.
(레드 노드는 연달아 나타날 수 없으며, 블랙 노드만이 레드 노드의 부모 노드가 될 수 있다.)
5. 어떤 노드로부터 시작되어 그에 속한 하위 리프 노드에 도달하는 모든 경로에는 
리프 노드를 제외하면 모두 같은 개수의 블랙 노드가 있다.

위 조건들을 만족하게 되면 레드-블랙 트리는 가장 중요한 특성을 나타내게 되는데,
"루트 노드부터 가장 먼 잎노드 경로까지의 거리가 가장 가까운 잎노드 경로까지의 거리의 두배 보다 항상 작다."
다시 말해서 레드-블랙 트리는 개략적으로 균형이 잡혀 있다. 따라서 삽입,삭제,검색 시 최악의 경우에서의
시간 복잡도가 트리의 높이(혹은 깊이)에 따라 결정되기 때문에 보통의 이진 탐색 트리에 비해 효율적이다.




C++로 옮겨 보자.
*/

#include <stdio.h>
#include <stdlib.h>

#define RED     0
#define BLACK   1

typedef struct node
{
    int color;
    int data;
    struct node* right;
    struct node* left;
    struct node* parent;
}node;

// should declare LEAF node = color: BLACK, data, no sibloing, only parent.
node* LEAF = {BLACK};

struct node *grandparent(struct node *n)
{
    if ((n != NULL) && (n->parent != NULL))
        return n->parent->parent;
    else
        return NULL;
}

struct node *uncle(struct node *n)
{
    struct node *g = grandparent(n);
    if (g == NULL)
        return NULL; // No grandparent means no uncle
    if (n->parent == g->left)
        return g->right;
    else
        return g->left;
}

struct node *sibling(struct node *n)
{
    if (n == n->parent->left)
        return n->parent->right;
    else
        return n->parent->left;
}

int is_leaf(struct node* n)
{
    /*
    * '''LEAF'''라는 노드를 struct node* 형식으로 하나 만들어주고 사용하면 된다.
        이 노드는 색깔이 검은색이고, 자식은 가질 수 없고 오직 부모만 가질 수 있다.
    */
    return (n == LEAF) ? 1 : 0;
}

void delete_one_child(struct node *n)
{
    /*
     * 선제조건: n이 최대 하나의 non-null 자식을 갖고 있음.
    */
    struct node *child = is_leaf(n->right) ? n->left: n->right;

    replace_node(n, child);
    if (n->color == BLACK) {
        if (child->color == RED)
            child->color = BLACK;
        else
            delete_case1(child);
    }
    free(n);
}

void replace_node(struct node* n, struct node* child)
{
    /*
     *앞에서 n의 부모가 NULL이 되는 경우를 delete_case에 오지 않게 미리 처리해주면 된다.
    */
    child->parent = n->parent;
    if (n->parent->left == n)
        n->parent->left = child;
    else if (n->parent->right == n)
        n->parent->right = child;
}

static void rotate_left(struct node *n)
{
    struct node *c = n->right;
    struct node *p = n->parent;

    if (c->left != NULL)
        c->left->parent = n;

    n->right = c->left;
    n->parent = c;
    c->left = n;
    c->parent = p;

    if (p != NULL) {
        if (p->left == n)
            p->left = c;
        else
            p->right = c;
    }
}

static void rotate_right(struct node *n)
{
    struct node *c = n->left;
    struct node *p = n->parent;

    if (c->right != NULL)
        c->right->parent = n;

    n->left = c->right;
    n->parent = c;
    c->right = n;
    c->parent = p;

    if (p != NULL) {
        if (p->right == n)
            p->right = c;
        else
            p->left = c;
    }
}