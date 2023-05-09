// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/GameModeBase.h"
#include "ABGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API AABGameMode : public AGameModeBase
{
	GENERATED_BODY()

	
// C++에서 접근 제한자 없이 멤버 변수 OR 함수 선언 시
// 클래스의 경우 private가 디폴트, 구조체의 경우 public 이 디폴트

public:
	AABGameMode();

	virtual void PostLogin(APlayerController* NewPlayer) override;
	
};
