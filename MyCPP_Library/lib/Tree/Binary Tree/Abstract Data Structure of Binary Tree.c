ADT BinaryTree
데이터 : 공백 루트 노드, 왼쪽 서브트리, 오른쪽 서브트리로 구성된 노드들의 유한 집합
연산 :
bt, bt1, bt2->BinaryTree; item->Element;

// 공백 이진 트리 생성 연산
createBT() :: = create an empty bin tree

// 이진 트리가 공백인지 확인하는 연산
isEmpty(bt) :: = if (bt is empty) then return true
else return false;

// 두 개의 이진 서브 트리를 연결하여 하나로 만드는 연산
makeBT(item, bt1, bt2) :: = return { item을 루트로 하고 bt1을 왼쪽, bt2를 오른쪽 서브트리 }

// 이진 트리의 왼쪽 서브 트리를 구하는 연산
leftSubtree(bt) :: = if (isEmpty(bt)) then return NULL
else return left subtree of bt;


// 이진 트리의 오른쪽 서브 트리를 구하는 연산
rightSubtree(bt) :: = if (isEmpty(bt)) then return NULL
else return right subtree of bt;

// 루트 노드의 데이터를 구하는 연산
data(bt) :: = if (isEmpty(bt)) then return NULL
else return the item in the root node of bt;
End BinaryTree