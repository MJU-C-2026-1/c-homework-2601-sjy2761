//1. 주석
/* 
  파일이름: 2st task.c
  작 성 자: 송 제 엽
  하 는 일: 헬스/벌크업 식단 및 운동 플래너 - 2차 과제
*/

//2. 전처리기
#include <stdio.h>
#include <stdlib.h>

//전역 변수 선언
char initial;

double current_weight, target_weight, weight_to_gain;

int target_days;
int daily_calorie = 0;
int protein_goal = 0;
int total_steps;

//함수 원형 선언

void setphase1goal();
int calcdailycalorie(double weight);
int calcproteingoal(double weight);

//매개변수
void analyzediet(int today_calorie, int today_protein);
void analyzeExercise(int today_exercise, int today_walk);

//3. int main()

int main()
{
    system("chcp 65001");

    //지역 변수
    int menu;
    int today_calorie;
    int today_protein;
    int today_exercise;
    int today_walk;

    while(1)
    {
        printf("\n====================================\n");
        printf("---[스마트 벌크업 플래너 : Phase 3]---\n");
        printf("=====================================\n");
        printf("1.신체 정보 및 목표 설정 (Phase 1)\n");
        printf("2.오늘 식단 및 운동 분석 (Phase 2)\n");
        printf("0.프로그램 종료\n");
        printf("-------------------------------------\n");
        printf("원하시는 메뉴 번호를 입력하세요:\n");
        scanf("%d", &menu);

        if(menu == 0)
        {
            printf("\n플래너를 종료합니다. 오늘도 득근하세요!\n");
            break;

        }
            
        switch(menu)
        {
              case 1:
                  setphase1goal();
                  break;
              case 2:
                  if(daily_calorie == 0)
                  {
                      printf(">> 경고: '1.신체 정보 및 목표 설정'을 먼저 진행해 주세요\n");
                      break;
                  }
              
              printf("---[스마트 벌크업 플래너: Phase 2]---\n");
              printf("오늘 섭취한 칼로리(kcal)를 입력 하시오.\n");
              scanf("%d", &today_calorie);
              printf("오늘 섭취 단백질(g)을 입력 하시오.\n");
              scanf("%d", &today_protein);
              printf("오늘 운동 시간(분)을 입력 하시오.\n");
              scanf("%d", &today_exercise);
              printf("오늘 걸음 수를 입력하시오.\n");
              scanf("%d", &today_walk);

              printf("\n=================================\n");
              printf("벌크업 플래너 Phase 2 [%C]님 분석 결과\n", initial);
              printf("-----------------------------------\n");

              analyzediet(today_calorie, today_protein);
              analyzeExercise(today_exercise, today_walk);
              break;

        default:
              printf("\n잘못된 번호입니다. 0, 1, 2 중에서 다시 선택해주세요.\n");
              break;
        }

   }
   return 0;
}
        
//목표 설정 함수
void setphase1goal()
{
    printf("---[스마트 벌크업 플래너 : Phase 1]\n");
    printf("사용자 이니셜을 입력하세요:");
    scanf(" %c", &initial);
    printf("현재 몸무게(kg):");
    scanf("%lf", &current_weight);
    printf("목표 몸무게(kg)");
    scanf("%lf", &target_weight);
    printf("목표 달성 기간 (일 단위):");
    scanf("%d", &target_days);

    weight_to_gain = target_weight - current_weight;
    total_steps = 10000;

    //매개변수를 던지고 return 값을 받아 전역변수 업데이트
    daily_calorie = calcdailycalorie(current_weight);
    protein_goal = calcproteingoal(current_weight);

    printf("\n================================\n");
    printf("벌크업 플래너 Phase 1 [%c]님 분석 결과\n", initial);
    printf("----------------------------------\n");
    printf("1.신체 분석: %.1lfkg -> %.1lfkg (총 %.1lfkg 증량 필요)\n", current_weight, target_weight, weight_to_gain);
    printf("2.목표 기간: %d일 이내 달성\n", target_days);
    printf("3.하루 권장 칼로라: %d kcal\n", daily_calorie);
    printf("4.하루 권장 단백질: %dg\n", protein_goal);
    printf("===================================\n");
}

int calcdailycalorie(double weight)
{
    return (int)(weight * 45);
}
int calcproteingoal(double weight)
{
    return (int)(weight * 2);
}

//식단 분석 및 벌크업 세부 판별 함수
void analyzediet(int today_calorie, int today_protein)
{
    //영양 섭취 달성도 평가
    if(today_calorie > daily_calorie - 100)
    {
        printf("1. 영양 섭취 달성도: 칼로리 초과! 체지방 급증을 주의하세요!\n");
    }
    else if(today_calorie > daily_calorie - 100)
    {
        printf("1.영양 섭취 달성도: 벌크업 목표 달성! 아주 훌륭합니다!\n");
    }
    else
    {
        printf("1.영양 섭취 달성도: 칼로리가 부족합니다. 더 섭취하세요!\n");
    }

    //클린 벌크업 vs 더티 벌크업 세부 판별
    if(today_calorie >= daily_calorie)
    {
      if(today_protein >= protein_goal)
      {
        printf("2.벌크업 세부 판별: 완벽한 '클린 벌크업' 입니다\n");
      }
      else
      {
        printf("2.벌크업 세부 판별: 칼로리는 채웠지만 단백질이 부족합니다. '더티 벌크업' 주의!\n");
      }
    }
}

//복합 운동 강도 분류 함수
void analyzeExercise(int today_exercise, int today_walk)
{
  if(today_exercise >= 60 && today_walk >= 10000)
  {
    printf("3.오늘의 운동: 고강도 완료!\n");
  }
  else if(today_exercise >= 30 || today_walk >= 5000)
  {
    printf("3.오늘의 운동: 중강도 완료!\n");
  }
  else
  {
    printf("3.오늘의 운동: 저강도 또는 휴식 완료\n");
  }
}

