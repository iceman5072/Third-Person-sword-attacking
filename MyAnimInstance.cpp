The logical part of parent class of animation blueprint used in animations

#include "items/MyAnimInstance.h"
#include "items/Doraemon.h"
#include "GameFramework/CharacterMovementComponent.h" 
#include "Kismet/KismetMathLibrary.h"

void UMyAnimInstance::NativeInitializeAnimation()
{
	
	Super::NativeInitializeAnimation();
	Character = Cast<ADoraemon>(TryGetPawnOwner());
	if (Character)
	{
		MovementInput = Character->GetCharacterMovement();
		
	}
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	
	Super::NativeUpdateAnimation(DeltaTime);
	if (MovementInput)
	{

		groundspeed=UKismetMathLibrary::VSizeXY(MovementInput->Velocity);
		 Falling=MovementInput->IsFalling();
		 CharacterStates = Character->GetCharacterState();
	}
}
