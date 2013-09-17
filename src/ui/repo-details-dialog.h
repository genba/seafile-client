#ifndef SEAFILE_CLIENT_REPO_DETAILS_DIALOG_H
#define SEAFILE_CLIENT_REPO_DETAILS_DIALOG_H

#include "ui_repo-details-dialog.h"
#include "api/server-repo.h"

class RepoDetailsDialog : public QDialog,
                          public Ui::RepoDetailsDialog
{
    Q_OBJECT

public:
    RepoDetailsDialog(const ServerRepo& repo, QWidget *parent=0);

private:
    Q_DISABLE_COPY(RepoDetailsDialog);

    ServerRepo repo_;
};

#endif // SEAFILE_CLIENT_REPO_DETAILS_DIALOG_H
