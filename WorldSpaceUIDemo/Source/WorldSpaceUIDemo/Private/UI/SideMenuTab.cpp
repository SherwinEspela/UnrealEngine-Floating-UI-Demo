// Copyright 2023 Sherwin Espela. All rights reserved.


#include "UI/SideMenuTab.h"
#include "Components/Image.h"

USideMenuTab::USideMenuTab()
{
	SetSelectionRegion(EDataBiosSelectionRegion::EDSR_SideMenu);
}

void USideMenuTab::NativeConstruct()
{
	Super::NativeConstruct();

	SetHighlight(false);
}

void USideMenuTab::SetHighlight(bool ShoudHighlight)
{
	auto SlateVisibility = ShoudHighlight ? ESlateVisibility::Visible : ESlateVisibility::Hidden;
	ImageBorder->SetVisibility(SlateVisibility);
}
