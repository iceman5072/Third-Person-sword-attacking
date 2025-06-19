The code of character which contains all the pointers etc which are used in logic

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "CharacterTypes.h"
#include "Doraemon.generated.h"

class UInputAction;
class UInputMappingContext;
class UGroomComponent;
class ABall;


UCLASS()
class GAMEIMPLEMENTATION_API ADoraemon : public ACharacter
{
	GENERATED_BODY()

public:
	
	ADoraemon();
	
	virtual void Tick(float DeltaTime) override;

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	UInputAction* Move;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* Character;
	
	void MoveForward(const FInputActionValue& Value);
	UPROPERTY(VisibleAnywhere,Category="Hair")
	UGroomComponent* Hair;
	UPROPERTY(VisibleAnywhere, Category = "Hair")	
	UGroomComponent* Eyebrow;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	UInputAction* LookAction;
	void looking(const FInputActionValue& value);
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	UInputAction* JumpAction;

	UPROPERTY(VisibleInstanceOnly)
	ABall* overlappingItem;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* EquipAction;
	void equipping(const FInputActionValue& value);
public:
	 
	FORCEINLINE void SetOverlapping(ABall* Item) { overlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState()  const { return CharacterState; }
private:
	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;
	EActionState Action = EActionState::EAS_Unoccupied;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* AttackingAction;
	void attacking(const FInputActionValue& value);

	//AnimationMontages
	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	UAnimMontage* AttackMontage;
	void AttackMontages();

};
