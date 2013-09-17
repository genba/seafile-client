#include <QtGui>

#include "repo-details-dialog.h"


RepoDetailsDialog::RepoDetailsDialog(const ServerRepo& repo, QWidget *parent)
    : QDialog(parent),
      repo_(repo)
{
    setupUi(this);

    setWindowTitle(tr("Details of %1").arg(repo.name));
}
