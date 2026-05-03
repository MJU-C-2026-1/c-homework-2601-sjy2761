/* 
  파일이름: 2st task.c
  작 성 자: 송 제 엽
  하 는 일: 헬스/벌크업 식단 및 운동 플래너 - 2차 과제
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  //1차 과제 - (목표 체중과 하루 권장 칼로리를 계산);
  system("chcp 65001");
  //[1. 변수 선언 - 자료형 3개 이상 사용]
  char initial;           //문자형: 사용자 이니셜
  double current_weight;  //실수형: 현재 몸무게
  double target_weight;   //실수형: 목표 몸무게
  double weight_to_gain;  //실수형: 중량 목표 무게
  int target_days;        //정수형: 목표 달성 기간 (예 :90일)
  int daily_calorie;      //정수형: 하루 목표 칼로리
  int protein_goal;       //정수형: 하루 목표 단백잘량
  int total_steps;        //정수형: 하루 목표 활동량
  int today_calorie;      //정수형: 오늘 섭취 칼로리
  int today_protein;      //정수형: 오늘 섭취 단백질
  int today_exercise;     //정수형: 오늘 운동 시간
  int today_walk;         //정수형: 오늘 걸음 수

  printf(" --- [스마트 벌크업 플래너: Phase 1] ---\n");

  //[2. 데이터 입력]
  printf("사용자 이니셜을 입력하세요: ");
  scanf(" %c", &initial);
  
  printf("현재 몸무게(kg): ");
  scanf("%lf", &current_weight);

  printf("목표 몸무게(kg): ");
  scanf("%lf", &target_weight);

  printf("목표 달성 기간(일 단위): ");
  scanf("%d", &target_days);

  //[3. 산술 연산]
  weight_to_gain = target_weight - current_weight;
  daily_calorie = (int)(current_weight * 45);
  protein_goal = (int)(current_weight * 2);
  total_steps = 10000;

  //[4.결과 리포트 출력]
  printf("\n =================================\n");
  printf("벌크업 플래너 Phase 1 [%c]님 분석 결과\n", initial);
  printf("------------------------------------\n");
  printf("1. 신체 분석: %.1lfkg -> %.1lfkg (총 %.1lfkg 증량 필요)\n", current_weight, target_weight, weight_to_gain);
  printf("2. 목표 기간: %d일 이내 달성\n", target_days);
  printf("3. 하루 권장 칼로리: %d kcal\n", daily_calorie);
  printf("4. 하루 권장 단백질: %dg/n", protein_goal);
  printf("5. 권장 일일 활동량: %d걸음 이상 \n", total_steps);
  printf("====================================\n");

  //2차과제 - 식단과 운동량 분석

  printf(" --- [스마트 벌크업 플래너: Phase 2] ---\n");

  printf("오늘 섭취한 칼로리(kcal)를 입력하시오.\n");
  scanf(" %d", &today_calorie);

  printf("오늘 섭취 단백질(g)을 입력 하시오\n");
  scanf(" %d", &today_protein);

  printf("오늘 운동 시간(분)을 입력하시오.\n");
  scanf(" %d", &today_exercise);

  printf("오늘 걸음 수를 입력하시오.\n");
  scanf(" %d", &today_walk);

  printf("\n=====================================\n");
  printf("벌크업 플래너 Phase 2 [%c]님 분석 결과\n");
  printf("---------------------------------------\n");

  if(today_calorie > daily_calorie + 300)              //영양 섭취 달성도 평가
  {
    printf("1. 영양 섭취 달성도: 칼로리 초과! 체지방 급증을 주의하세요!\n");
  }
  else if(today_calorie > daily_calorie - 100)
  {
    printf("1. 영양 섭취 달성도: 벌크업 목표 달성! 아주 훌륭합니다!\n");
  }

  if(today_calorie >= daily_calorie)                   //클린 벌크업 vs 더티 벌크업 세부 판별
  {
      if(today_calorie >= daily_calorie)
      {
        printf("2. 벌크업 세부 판별: 완벽한 '클린 벌크업'입니다\n");
      }
      else
      {
        printf("2. 벌크업 세부 판별: 칼로리는 채웠지만 단백질이 부족합니다. '더티 벌크업'주의!\n");
      }
    }

  if(today_exercise >= 60 && today_walk >= 10000)
  {
    printf("3. 오 늘 의  운 동: 고강도 완료!\n");
  }
  else if(today_exercise >= 30 || today_walk >= 5000)
  {
    printf("3. 오 늘 의  운 동: 중강도 완료!\n");
  }
  else
  {
    printf("3. 오 늘 의  운 동: 저강도 또는 휴식 완료\n");
  }
  return 0;
}