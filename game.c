#include<stdio.h>
char arr[3][3] = { {'_','_','_'},{'_','_','_'},{'_','_','_'} }; //게임판 작성
void print() { // 게임판 생성 함수
	for (int i = 0; i < 3; i++) { // 3x3 틱택토 게임판
		for (int j = 0; j < 3; j++)
			printf("%c", arr[i][j]); // 생성
		printf("\n");
	}
}
void scano(int count) { //게임말 입력 함수
	int x = 0, y = 0;
	scanf("%d", &x);//게임말의 x좌표
	scanf("%d", &y);//게임말의 y좌표
	
	if (arr[y- 1][x - 1] != '_' || x > 3 || y > 3) {// 게임말을 두려는 곳에 게임말이 있는 경우
		printf("다른곳에 두세요.");
		scano(count);//입력순서로 다시
		return;
	}
	//count 변수 == 게임말 순서 체크
	char tmp = 'o';
	if (count % 2 != 0) {
		tmp = 'x';
	}
	arr[y-1][x-1] = tmp; 
	
}

int check() { // 게임의 승리 판단 함수
	for (int i = 0; i < 3; i++) {//세로줄로 연속 3개가 있는 경우
		if (arr[0][i] == '_' || arr[1][i] == '_' || arr[2][i] == '_')//빈칸 체크
		{
			continue;
		}
		if ((arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] == arr[i][2])) {
			if (arr[i][0] == 'o') {
				return 0;  // 'o'가 이기면 return 0
			}
			else if (arr[i][0] == 'x') {
				return 1;  // 'x'가 이기면 return 1 
			}
			else {
				return 2; // 이긴 사람이 없으면 return 2
			}
		}
	}
	for (int j = 0; j < 3; j++){//가로줄로 연속 3개가 있는 경우
		if (arr[j][0] == '_' || arr[j][1] == '_' || arr[j][2] == '_') //빈칸체크
		{
			continue;
		}
		if ((arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] == arr[2][j])) {
			if (arr[0][j] == 'o') {
				return 0;  // 'o'가 이기면 return 0
			}
			else if (arr[0][j] == 'x') {
				return 1;  // 'x'가 이기면 return 1 
			}
			else {
				return 2;  // 이긴 사람이 없으면 return 2
			}
		}
	}
	
	if (arr[0][0] != '_' && arr[1][1] != '_' && arr[2][2] != '_') {  //빈칸체크
		//우하향으로 연속 3개가 있는 경우 
		if (arr[0][0] == 'o' &&arr[1][1]=='o'&&arr[2][2]=='o') {
			return 0;  // 'o'가 이기면 return 0
		}
		else if (arr[0][0] == 'x' && arr[1][1] == 'x' && arr[2][2] == 'x') {
			return 1;  // 'x'가 이기면 return 1 
		}
		else {
			return 2;  // 이긴 사람이 없으면 return 2
		}
	}
	if (arr[0][2] != '_' && arr[1][1] != '_' && arr[2][0] != '_') {  //빈칸체크
		//우상향으로 연속 3개가 있는 경우
		if (arr[0][2] == 'o' && arr[1][1] == 'o' && arr[2][0] == 'o') {
			return 0;  // 'o'가 이기면 return 0
		}
		else if (arr[0][2]== 'x' && arr[1][1] == 'x' && arr[2][0] == 'x') {
			return 1; // 'x'가 이기면 return 1 
		}
		else {
			return 2;  // 이긴 사람이 없으면 return 2
		}
	}
}

void result_print(int who) { //승리한 사람 출력 함수
	if (who == 0) {  // return 0 값을 받으면 'o' 승리
		printf("'o' win!");
		printf("\n");
	}
	if (who == 1) { // return 1 값을 받으면 'x' 승리
		printf("'x' win!");
		printf("\n");
	}
	if (who == 2) {  // return 2값을 받으면 출력하지 않음
		return;
	}
}

int main()
{	
	int count = 0;//게임말 순서 체크 변수
	print();
	while (1) {//승리 전까지 무한루프
		int check_result = check(); //check한 값의 결과
		result_print(check_result); //누가 승리 했는지 출력
		if (check_result == 0 || check_result == 1)//누구라도 이긴다면 무한루프 탈출 => 게임 종료
			break;
		scano(count); //게임말 위치 입력
		print(); //게임판 출력
		count++; // 순서 교체
	}
	return 0;
}

/*틱택토를 만들었을 때 어려웠던점
1. 빈칸을 원래는 그냥 아무것도 없는 걸로 생각하고 만들었다가 빈칸을 체크해줘야 한다는것을 깨닫고 빈칸체크를 했던 부분이 어려웠었던거 같습니다.

2. 승리 조건을 생각을 할수는 있었으나 제가 생각한 부분을 코드를 직접짜서 표현했어야 했던 부분이 어려웠었던것 같습니다.


문법
1.틱택토에서의 주요 문법은 2차원 배열인데, 특히 그중에서도 2차원 배열을 출력을 하고, 2차원 배열 안을 검사하는 부분이 중요했던것 같습니다.*/