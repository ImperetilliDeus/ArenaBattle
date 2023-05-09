// Fill out your copyright notice in the Description page of Project Settings.


#include "ABGameMode.h"
#include "ABCharacter.h"
#include "ABPlayerController.h"

AABGameMode::AABGameMode() {

	// 해당 게임모드의 기본 폰을 지정하는 코드
	DefaultPawnClass = AABCharacter::StaticClass();

	// 해당 게임모드의 기본 플레이어 컨트롤러를 지정하는 코드
	PlayerControllerClass = AABPlayerController::StaticClass();

	// 블루프린트로 생성된 Pawn을 디폴트로 사용하고자 한다면 해당 코드 사용
	// 끝에 _C 붙여서 가져오기
	//static ConstructorHelpers::FClassFinder<APawn> BP_PAWN_C(TEXT("/Game/Blueprints/BP_Pawn.BP_Pawn_C"));

	//if (BP_PAWN_C.Succeeded()) {
	//	DefaultPawnClass = BP_PAWN_C.Class;
	//}
}

void AABGameMode::PostLogin(APlayerController* NewPlayer) {
	ABLOG(Warning, TEXT("PostLogin Begin"));
	Super::PostLogin(NewPlayer);
	ABLOG(Warning, TEXT("PostLogin End"));
}

