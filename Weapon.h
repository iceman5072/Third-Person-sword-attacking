The header file for weapon class
#include "Weapon.generated.h"

class ADoraemon;
UCLASS()
class GAMEIMPLEMENTATION_API AWeapon : public ABall
{
	GENERATED_BODY()
	
protected:
	
	virtual void onsphereoverlapp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
	virtual void endsphereoverlapp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
	ADoraemon* character;

public:
	void equip(USceneComponent* InParent,FName InSocketName);

};
