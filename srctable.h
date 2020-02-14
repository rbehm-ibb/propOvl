// *************************************
// * Created by model-builder, V1.9
// * Fri Feb 14 17:11:53 2020 by behm
// *************************************

#ifndef SRCTABLE_H
#define SRCTABLE_H

struct SpinSrc
{
	SpinSrc() {}
	friend QDebug operator<<(QDebug dbg, const SpinSrc &d);
	QString src;
	QString out;
	int resultCode;
	QString result;
};
typedef QVector<SpinSrc> SpinSrcVector;
Q_DECLARE_METATYPE(SpinSrc)

class SrcTable : public QAbstractTableModel
{
	Q_OBJECT
public:
	enum Colums { Src, Out, ResultCode, Result, NCols };
	Q_ENUMS(Colums)
	explicit SrcTable(QObject *parent = nullptr);
	~SrcTable();
	void saveConf(QSettings *setting) const;
	void loadConf(QSettings *setting);
	virtual int rowCount(const QModelIndex & = QModelIndex()) const { return m_data.count(); }
	virtual int columnCount(const QModelIndex & = QModelIndex()) const { return NCols; }
	virtual bool hasChildren(const QModelIndex & = QModelIndex()) const { return false; }
	virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;
	virtual QVariant data(const QModelIndex &index, int role) const;
	virtual Qt::ItemFlags flags(const QModelIndex & = QModelIndex()) const { return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemNeverHasChildren | Qt::ItemIsEditable; }
	virtual bool setData(const QModelIndex &index, const QVariant &value, int role);
	void clear();
	virtual bool insertRows(int row, int count, const QModelIndex &parent);
	virtual bool removeRows(int row, int count, const QModelIndex &parent);
	const SpinSrcVector & data() const { return m_data; }
	void setData(const SpinSrcVector &d);
	const SpinSrc & data(int row) const { return m_data.at(row); }
private:
	const QStringList m_header;
	const QVector<int> m_stdRoles;
	SpinSrcVector m_data;
};

#endif // SRCTABLE_H
