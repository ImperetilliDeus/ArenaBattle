// Fill out your copyright notice in the Description page of Project Settings.


#include "ABAnimInstance.h"

UABAnimInstance::UABAnimInstance() {
	CurrentPawnSpeed = 0.0f;
	IsInAir = false;
	IsDead = false;

	static ConstructorHelpers::FObjectFinder<UAnimMontage> ATTACK_MONTATGE(TEXT("/Game/Book/Animations/SK_Mannequin_Skeleton_Montage.SK_Mannequin_Skeleton_Montage"));
	if (ATTACK_MONTATGE.Succeeded()) {
		AttackMontage = ATTACK_MONTATGE.Object;
	}
}

void UABAnimInstance::NativeUpdateAnimation(float DeltaSeconds) {
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (!::IsValid(Pawn)) return;
	
	if(!IsDead){
		CurrentPawnSpeed = Pawn->GetVelocity().Size();
		auto Character = Cast<ACharacter>(Pawn);
		if (Character) {
			IsInAir = Character->GetMovementComponent()->IsFalling();
		}
	}
}
void UABAnimInstance::PlayerAttackMontage() {
	ABCHECK(!IsDead);
	Montage_Play(AttackMontage, 0.8f);
	
}

void UABAnimInstance::JumpToAttackMontageSection(int32 NewSection)
{
	ABCHECK(!IsDead);
	ABCHECK(Montage_IsPlaying(AttackMontage));
	Montage_JumpToSection(GetAttackMontageSectionName(NewSection), AttackMontage);
}

void UABAnimInstance::AnimNotify_AttackHitCheck()
{
	OnAttackHitCheck.Broadcast();
}

void UABAnimInstance::AnimNotify_NewAttackCheck()
{
	OnNewAttackCheck.Broadcast();

}

FName UABAnimInstance::GetAttackMontageSectionName(int32 Section)
{
	ABCHECK(FMath::IsWithinInclusive<int32>(Section, 1, 4), NAME_None);
	// ��Ÿ�� ���� �̸� �������°ǵ� Attack%d ���� �� �ٿ��־�
	// Attack1, Attack2 �̷��� �������µ� ���� �ؼ� ��Ÿ�� ���� ��ã�ƿ��� ���� ��ģ�ٰ�
	// �ѽð��� ���ȳ�... ��¥ �������� ��...
	return FName(*FString::Printf(TEXT("Attack%d"), Section));
}

