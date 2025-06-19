The character cpp whre the logic goes


#include "items/Doraemon.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GroomComponent.h"
#include "items/Weapons/Weapon.h"


ADoraemon::ADoraemon()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	Hair = CreateDefaultSubobject<UGroomComponent>(TEXT("Hair"));
	Hair->SetupAttachment(GetMesh());
	Hair->AttachmentName = FString("head");
	Eyebrow = CreateDefaultSubobject<UGroomComponent>(TEXT("Eyebrow"));
	Eyebrow->SetupAttachment(GetMesh());
	Eyebrow->AttachmentName = FString("head");
}

void ADoraemon::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* playercontroller = Cast<APlayerController>(GetController());
	if (playercontroller)
	{
		UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playercontroller->GetLocalPlayer());
		if (subsystem)
		{
			subsystem->AddMappingContext(Character, 0);
		}
	}
}

void ADoraemon::MoveForward(const FInputActionValue& Value)
{
	
	if (Controller)
	{
		const FVector2D MovementVector = Value.Get<FVector2D>();
		const FRotator Rotation = Controller->GetControlRotation();
		FRotator YawRotataion(0.f, Rotation.Yaw, 0.f);

		const FVector ForwardVector = FRotationMatrix(YawRotataion).GetUnitAxis(EAxis::X);
		AddMovementInput(ForwardVector, MovementVector.Y);
		const FVector RightVector = FRotationMatrix(YawRotataion).GetUnitAxis(EAxis::Y);
		AddMovementInput(RightVector, MovementVector.X);
	}
}

void ADoraemon::looking(const FInputActionValue& value)
{
	if (GetController())
	{
		const FVector2D MovementVector  = value.Get<FVector2D>();
		AddControllerYawInput(MovementVector.X);
		AddControllerPitchInput(MovementVector.Y);
	}
}

void ADoraemon::equipping(const FInputActionValue& value)
{
	bool pressed = value.Get<bool>();
	AWeapon* Weapon = Cast<AWeapon>(overlappingItem);
	if (Weapon)
	{
		Weapon->equip(GetMesh(), FName("hand_rSocket"));
	}
	 CharacterState = ECharacterState::ECS_EquippedOneHandWeapon;
}

void ADoraemon::attacking(const FInputActionValue& value)
{
	bool attack = value.Get<bool>();
	if (attack)
	{
		if (Action == EActionState::EAS_Unoccupied)
		{
			AttackMontages();
			Action = EActionState::EAS_Attacking;
		}
	}
}

void ADoraemon::AttackMontages()
{
	

		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
		if (AnimInstance && AttackMontage)
		{
			AnimInstance->Montage_Play(AttackMontage);
		const 	int32 Selection = FMath::RandRange(0, 1);
			FName Section = FName();
			switch (Selection)
			{
			case 0:
				Section = FName(TEXT("Attack1"));
				break;
			case 1:
				Section = FName(TEXT("Attack2"));
				break;
			default:
				break;
			}
			AnimInstance->Montage_JumpToSection(Section, AttackMontage);
		}
	
}
