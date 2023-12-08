ADT BinaryTree
������ : ���� ��Ʈ ���, ���� ����Ʈ��, ������ ����Ʈ���� ������ ������ ���� ����
���� :
bt, bt1, bt2->BinaryTree; item->Element;

// ���� ���� Ʈ�� ���� ����
createBT() :: = create an empty bin tree

// ���� Ʈ���� �������� Ȯ���ϴ� ����
isEmpty(bt) :: = if (bt is empty) then return true
else return false;

// �� ���� ���� ���� Ʈ���� �����Ͽ� �ϳ��� ����� ����
makeBT(item, bt1, bt2) :: = return { item�� ��Ʈ�� �ϰ� bt1�� ����, bt2�� ������ ����Ʈ�� }

// ���� Ʈ���� ���� ���� Ʈ���� ���ϴ� ����
leftSubtree(bt) :: = if (isEmpty(bt)) then return NULL
else return left subtree of bt;


// ���� Ʈ���� ������ ���� Ʈ���� ���ϴ� ����
rightSubtree(bt) :: = if (isEmpty(bt)) then return NULL
else return right subtree of bt;

// ��Ʈ ����� �����͸� ���ϴ� ����
data(bt) :: = if (isEmpty(bt)) then return NULL
else return the item in the root node of bt;
End BinaryTree