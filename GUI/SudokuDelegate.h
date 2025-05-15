#ifndef SUDOKUDELEGATE_H
#define SUDOKUDELEGATE_H

#include <QStyledItemDelegate>

class SudokuDelegate : public QStyledItemDelegate {
public:
    using QStyledItemDelegate::QStyledItemDelegate;

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;
};

#endif // SUDOKUDELEGATE_H
