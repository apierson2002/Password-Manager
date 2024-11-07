


#include <memory>

#include <Wt/WBreak.h>
#include <Wt/WComboBox.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

#include "petForm.h"

using namespace Wt;

petForm::petForm(petShop::petList& pl) : pl {pl}
{
       	addWidget(std::make_unique<WText>("Pet name: "));
	 nameEdit = addWidget(std::make_unique<WLineEdit>());
	 nameEdit->setFocus();

	 addWidget(std::make_unique<WBreak>());

	 addWidget(std::make_unique<WText>("Pet type: "));
	 typeEdit = addWidget(std::make_unique<WComboBox>());
	 for (auto it=pl.typeList.cbegin(); it!=pl.typeList.cend(); ++it)
		 typeEdit->addItem(it->getText());
	 typeEdit->setNoSelectionEnabled(true);
	 typeEdit->setCurrentIndex(-1);

	 addWidget(std::make_unique<WBreak>());

	 auto cancelButton = addWidget(std::make_unique<WPushButton>("Cancel"));
	 cancelButton->setMargin(5, Side::Left | Side::Top);
	 cancelButton->setLink(WLink(LinkType::InternalPath, "/home"));

	 OkButton = addWidget(std::make_unique<WPushButton>("OK"));
	 OkButton->setMargin(5, Side::Left | Side::Top);
	 // connect OkButton in derived class
 }
