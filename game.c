#include<stdio.h>
char arr[3][3] = { {'_','_','_'},{'_','_','_'},{'_','_','_'} }; //������ �ۼ�
void print() { // ������ ���� �Լ�
	for (int i = 0; i < 3; i++) { // 3x3 ƽ���� ������
		for (int j = 0; j < 3; j++)
			printf("%c", arr[i][j]); // ����
		printf("\n");
	}
}
void scano(int count) { //���Ӹ� �Է� �Լ�
	int x = 0, y = 0;
	scanf("%d", &x);//���Ӹ��� x��ǥ
	scanf("%d", &y);//���Ӹ��� y��ǥ
	
	if (arr[y- 1][x - 1] != '_' || x > 3 || y > 3) {// ���Ӹ��� �η��� ���� ���Ӹ��� �ִ� ���
		printf("�ٸ����� �μ���.");
		scano(count);//�Է¼����� �ٽ�
		return;
	}
	//count ���� == ���Ӹ� ���� üũ
	char tmp = 'o';
	if (count % 2 != 0) {
		tmp = 'x';
	}
	arr[y-1][x-1] = tmp; 
	
}

int check() { // ������ �¸� �Ǵ� �Լ�
	for (int i = 0; i < 3; i++) {//�����ٷ� ���� 3���� �ִ� ���
		if (arr[0][i] == '_' || arr[1][i] == '_' || arr[2][i] == '_')//��ĭ üũ
		{
			continue;
		}
		if ((arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] == arr[i][2])) {
			if (arr[i][0] == 'o') {
				return 0;  // 'o'�� �̱�� return 0
			}
			else if (arr[i][0] == 'x') {
				return 1;  // 'x'�� �̱�� return 1 
			}
			else {
				return 2; // �̱� ����� ������ return 2
			}
		}
	}
	for (int j = 0; j < 3; j++){//�����ٷ� ���� 3���� �ִ� ���
		if (arr[j][0] == '_' || arr[j][1] == '_' || arr[j][2] == '_') //��ĭüũ
		{
			continue;
		}
		if ((arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] == arr[2][j])) {
			if (arr[0][j] == 'o') {
				return 0;  // 'o'�� �̱�� return 0
			}
			else if (arr[0][j] == 'x') {
				return 1;  // 'x'�� �̱�� return 1 
			}
			else {
				return 2;  // �̱� ����� ������ return 2
			}
		}
	}
	
	if (arr[0][0] != '_' && arr[1][1] != '_' && arr[2][2] != '_') {  //��ĭüũ
		//���������� ���� 3���� �ִ� ��� 
		if (arr[0][0] == 'o' &&arr[1][1]=='o'&&arr[2][2]=='o') {
			return 0;  // 'o'�� �̱�� return 0
		}
		else if (arr[0][0] == 'x' && arr[1][1] == 'x' && arr[2][2] == 'x') {
			return 1;  // 'x'�� �̱�� return 1 
		}
		else {
			return 2;  // �̱� ����� ������ return 2
		}
	}
	if (arr[0][2] != '_' && arr[1][1] != '_' && arr[2][0] != '_') {  //��ĭüũ
		//��������� ���� 3���� �ִ� ���
		if (arr[0][2] == 'o' && arr[1][1] == 'o' && arr[2][0] == 'o') {
			return 0;  // 'o'�� �̱�� return 0
		}
		else if (arr[0][2]== 'x' && arr[1][1] == 'x' && arr[2][0] == 'x') {
			return 1; // 'x'�� �̱�� return 1 
		}
		else {
			return 2;  // �̱� ����� ������ return 2
		}
	}
}

void result_print(int who) { //�¸��� ��� ��� �Լ�
	if (who == 0) {  // return 0 ���� ������ 'o' �¸�
		printf("'o' win!");
		printf("\n");
	}
	if (who == 1) { // return 1 ���� ������ 'x' �¸�
		printf("'x' win!");
		printf("\n");
	}
	if (who == 2) {  // return 2���� ������ ������� ����
		return;
	}
}

int main()
{	
	int count = 0;//���Ӹ� ���� üũ ����
	print();
	while (1) {//�¸� ������ ���ѷ���
		int check_result = check(); //check�� ���� ���
		result_print(check_result); //���� �¸� �ߴ��� ���
		if (check_result == 0 || check_result == 1)//������ �̱�ٸ� ���ѷ��� Ż�� => ���� ����
			break;
		scano(count); //���Ӹ� ��ġ �Է�
		print(); //������ ���
		count++; // ���� ��ü
	}
	return 0;
}

/*ƽ���並 ������� �� ���������
1. ��ĭ�� ������ �׳� �ƹ��͵� ���� �ɷ� �����ϰ� ������ٰ� ��ĭ�� üũ����� �Ѵٴ°��� ���ݰ� ��ĭüũ�� �ߴ� �κ��� ����������� �����ϴ�.

2. �¸� ������ ������ �Ҽ��� �־����� ���� ������ �κ��� �ڵ带 ����¥�� ǥ���߾�� �ߴ� �κ��� ����������� �����ϴ�.


����
1.ƽ���信���� �ֿ� ������ 2���� �迭�ε�, Ư�� ���߿����� 2���� �迭�� ����� �ϰ�, 2���� �迭 ���� �˻��ϴ� �κ��� �߿��ߴ��� �����ϴ�.*/