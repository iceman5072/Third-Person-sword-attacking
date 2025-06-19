The header of animinstance

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterTypes.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
class ADoraemon;
class UCharacterMovementComponent;
UCLASS()
class GAMEIMPLEMENTATION_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;
	UPROPERTY(BlueprintReadWrite)
	ADoraemon* Character;
	UPROPERTY(BlueprintReadWrite,Category="Movement")
	UCharacterMovementComponent* MovementInput;
	UPROPERTY(BlueprintReadWrite,Category="Movement")
	float groundspeed;
	UPROPERTY(BlueprintReadOnly,Category="MovmentInput")
	bool Falling;
	UPROPERTY(BlueprintReadOnly,Category="CharacterState")
	ECharacterState CharacterStates;
};
