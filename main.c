//1.주석
/*
    강좌:C언어
    파일명:4th_task.c
    설 명:헬스/벌크업 식단 및 운동 플래너 - 4차 과제 (배열 및 포인터 활용)
    작성자: 60231930 송제엽
*/

//2. 전처리기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define DAYS 7


//전역 변수
char user_name[20];
double current_weight, target_weight, weight_to_gain;
int target_days;
int daily_calorie = 0;
int protein_goal = 0;
int total_steps;

//함수 원형 선언
void setPhase1Goal();
int calcDailyCalorie(double weight);
int calcProteinGoal(double weight);

void inputWeeklyData(int *calorie_arr, int *protein_arr, int size);
void analyzeWeeklyDiet(int calorie_arr[], int protein_arr[], int size);

//3. int main
int main()
{
  system("chcp 65001");

  int menu; 

  int weekly_calories[DAYS] = {0};
  int weekly_proteins[DAYS] = {0};
  int data_entered = 0;

  while(1)
  {
    printf("\n==================================\n");
    printf(" ---[스마트 벌크업 플래너 : Phase 4]---\n");
    printf("====================================\n");
    printf("1. 신체 정보 및 목표 설정 (Phase 1)\n");
    printf("2. 주간 식단 데이터 입력 \n");
    printf("3. 주간 식단 조회 및 분석\n");
    printf("0. 프로그램 종료\n");
    printf("-------------------------------------\n");
    printf("원하시는 메뉴 번호를 입력하세요:");
    scanf("%d", &menu);

    if(menu == 0)
    {
      printf("\n 플래너를 종료합니다. 오늘도 득근하세요!\n");
      break;
    }

    switch(menu)
    {
      case 1:
        setPhase1Goal();
        break;
      case 2:
        if(daily_calorie == 0)
        {
          printf(">>경고: '1. 신체 정보 및 목표 설정'을 먼저 진행해주세요\n");
          break;
        }
        inputWeeklyData(weekly_calories, weekly_proteins, DAYS);
        data_entered = 1;
        break;
      case 3:
        if(daily_calorie == 0)
        {
          printf(">>경고: '1.신체 정보 및 목표 설정'을 먼저 진행해 주세요\n");
          break;
        }
        if(data_entered == 0)
        {
          printf(">>경고: '2.주간 식단 데이터 입력'을 먼저 진행해주세요\n ");
          break;
        }
        analyzeWeeklyDiet(weekly_calories, weekly_proteins, DAYS);
        break;

        default:
          printf("\n잘못된 번호입니다. 0, 1, 2, 3중에서 다시 선택해주세요.\n");
          break;
    }

  }

  return 0;
}

//1, 목표 설정 함수
void setPhase1Goal()
{
  printf("\n ---[스마트 벌크업 플래너: Phase 1]---\n");
  printf("사용자 이름을 입력하세요(영어)");
  scanf(" %s", user_name);
  printf("현재 몸무게(kg):");
  scanf("%lf", &current_weight);
  printf("목표 몸무게(kg):");
  scanf("%lf", &target_weight);
  printf("목표 달성 기간(일 단위):");
  scanf("%d", &target_days);

  weight_to_gain = target_weight - current_weight;
  total_steps = 10000;

  daily_calorie = calcDailyCalorie(current_weight);
  protein_goal = calcProteinGoal(current_weight);

  printf("\n=====================================\n");
  printf("벌크업 플래너 Phase 1 [%s]님 분석 결과\n", user_name);
  printf("---------------------------------------\n");
  printf("1. 신체 분석: %.1lfkg - >%.1lfkg (총 %.1lfkg 증량 필요)\n", current_weight, target_weight, weight_to_gain);
  printf("2. 목표 기간: %d일 이내 달성\n", target_days);
  printf("3. 하루 권장 칼로리: %d kcal\n", daily_calorie);
  printf("4. 하루 권장 단백질: %dg\n", protein_goal);
  printf("5. 권장 일일 활동량: %d 걸음 이상 \n", total_steps);
  printf("=======================================\n");
}

int calcDailyCalorie(double weight)
{
  return (int)(weight * 45);
}
int calcProteinGoal(double weight)
{
  return (int)(weight * 2);
}

//2.주간 데이터 입력 함수
void inputWeeklyData(int *calorie_arr, int *protein_arr, int size)
{
  printf("\n ---[스마트 벌크업 플래너: Phase 4 주간 입력]---\n");
  printf(">> %d일간의 식단 데이터를 차례대로 입력합니다.\n", size);

  int *p_cal = calorie_arr;
  int *p_pro = protein_arr;

  int temp_input;
  for(int i = 0; i < size; i++)
  {
    printf("[%d 일자]오늘 섭취 칼로리(kcal):", i + 1);
    scanf("%d", &temp_input);

    *(p_cal + i) = temp_input;

    printf("[%d일자] 오늘 섭취 단백질(g):", i + 1);
    scanf("%d", &temp_input);

    *(p_pro + i) = temp_input;
    printf("---------------------------------------------\n");
  }
  printf(">>주간 식단 데이터가 포인터 연산을 통해 배열에 안전하게 저장되었습니다.\n");
}

//3. 주간 데이터 조회 및 분석 함수
void analyzeWeeklyDiet(int calorie_arr[],int protein_arr[], int size)
{
  int total_calories = 0;
  int total_proteins = 0;

  printf("\n============================\n");
  printf("벌크업 플래너 Phase 4[%s]님 주간 종합 분석\n", user_name);
  printf("-------------------------------\n");
  printf("[주간 기록 데이터 출력 ]");

  for(int i = 0; i < size; i++)
  {
    printf("%d일자 -> 섭취 칼로리: %d kcal | 섭취 단백질: %dg\n", i + 1, calorie_arr[i], protein_arr[i]);
    total_calories += calorie_arr[i];
    total_proteins += protein_arr[i];
}

double avg_calorie = (double)total_calories / size;
double avg_protein = (double)total_proteins / size;

printf("----------------------------------\n");
printf("[주간 통계 및 최종 피드백]\n");
printf("1.주간 평균 섭취 칼로리: %.1f kcal (일일 목표: %d kcal)\n", avg_calorie, daily_calorie);
printf("2.주간 평균 섭취 단백질: %.1f g(일일 목표: %d g)\n", avg_protein, protein_goal);
printf("----------------------------------\n");

if(avg_calorie > daily_calorie + 300)
{
  printf("3. 종합 영양 평가: 칼로리 초과 상태입니다 ! 체지방 급증을 주의하세요!\n");
}
else if(avg_calorie > daily_calorie - 100)
{
  printf("3. 종합 영양 평가: 주간 벌크업 목표 칼로리 달성! 아주 훌륭합니다!\n");
}
else
{
  printf("3. 종합 영양 평가: 칼로리가 전체적으로 부족합니다. 식사량을 더 늘리세요\n");
}

if(avg_calorie > daily_calorie + 300)
{
  if(avg_protein >= protein_goal)
  {
    printf("4. 벌크업 세부 판별: 영양 비율이 완벽한 '클린 벌크업' 주간 이었습니다.\n");
  }
  else
  {
    printf("4. 벌크업 세부 판별: 칼로리는 채웠지만 단백질이 부족합니다. '더티 벌크업' 주의!\n");
  }
}
printf("====================================\n");
}