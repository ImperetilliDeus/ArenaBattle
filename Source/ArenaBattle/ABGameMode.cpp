// Fill out your copyright notice in the Description page of Project Settings.


#include "ABGameMode.h"
#include "ABCharacter.h"
#include "ABPlayerController.h"

AABGameMode::AABGameMode() {

	// �ش� ���Ӹ���� �⺻ ���� �����ϴ� �ڵ�
	DefaultPawnClass = AABCharacter::StaticClass();

	// �ش� ���Ӹ���� �⺻ �÷��̾� ��Ʈ�ѷ��� �����ϴ� �ڵ�
	PlayerControllerClass = AABPlayerController::StaticClass();

	// �������Ʈ�� ������ Pawn�� ����Ʈ�� ����ϰ��� �Ѵٸ� �ش� �ڵ� ���
	// ���� _C �ٿ��� ��������
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

