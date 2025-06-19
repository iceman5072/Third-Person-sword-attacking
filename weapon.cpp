The logical part of weapon
#include "items/Weapons/Weapon.h"


void AWeapon::onsphereoverlapp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::onsphereoverlapp(  OverlappedComponent, OtherActor,   OtherComp,  OtherBodyIndex,  bFromSweep, SweepResult);
	
}

void AWeapon::endsphereoverlapp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::endsphereoverlapp(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}

void AWeapon::equip(USceneComponent* InParent, FName InSocketName)
{
	FAttachmentTransformRules Transform(EAttachmentRule::SnapToTarget, true);
      item->AttachToComponent(InParent, Transform, InSocketName);
}
