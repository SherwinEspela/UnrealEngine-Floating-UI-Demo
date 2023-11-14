// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DataBiosMajorSkillsWidget.h"
#include "UI/SkillWidget.h"
#include "Components/UniformGridPanel.h"
#include "Containers/Array.h"

void UDataBiosMajorSkillsWidget::NativeConstruct()
{
	Super::NativeConstruct();

}

void UDataBiosMajorSkillsWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	LoadSkills();
}

void UDataBiosMajorSkillsWidget::LoadSkills()
{
	TArray<USkillWidget*> SkillsWidgets;
	if (SkillsDataTable)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Skills data table available...."));

		TArray<FName> RowNames = SkillsDataTable->GetRowNames();
		for (FName RowName : RowNames)
		{
			FMajorSkillsRow* Row = SkillsDataTable->FindRow<FMajorSkillsRow>(RowName, "");
			USkillWidget* SW = CreateWidget<USkillWidget>(GetWorld(), SkillWidgetClass);

			if (SW)
			{
				//UE_LOG(LogTemp, Warning, TEXT("Skill Name ====== %s"), *Row->SkillName);
				SW->SetValues(Row->SkillIcon, Row->SkillName, Row->Level);
				SkillsWidgets.Add(SW);
			}
		}

		int Index = 0;
		for (size_t row = 0; row < 2; row++)
		{
			for (size_t col = 0; col < 3; col++)
			{
				auto SW = SkillsWidgets[Index];
				CellsGrid->AddChildToUniformGrid(SW, row, col);
				Index++;
			}
		}
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("Skills data table NULL...."));
	}
}
