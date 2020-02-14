// *************************************
// * Created by model-builder, V1.9
// * Fri Feb 14 17:11:53 2020 by behm
// *************************************

#include "srctable.h"

SrcTable::SrcTable(QObject *parent)
	: QAbstractTableModel(parent)
	, m_header( { "Src", "Out", "ResultCode", "Result" })
	, m_stdRoles( { Qt::DisplayRole, Qt::EditRole })
{
}

SrcTable::~SrcTable()
{
}

void SrcTable::clear()
{
	beginResetModel();
	m_data.clear();
	endResetModel();
}

void SrcTable::setData(const SpinSrcVector &d)
{
	beginResetModel();
	m_data = d;
	endResetModel();
}

bool SrcTable::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (index.isValid() && index.row() < m_data.count())
	{
		auto &t = m_data[index.row()];
		switch (role)
		{
		case Qt::DisplayRole:
		case Qt::EditRole:
			switch (index.column())
			{
			case Src:
			{
				const QString v = value.toString();
				if (v != t.src)
				{
					t.src = v;
					emit dataChanged(index, index, m_stdRoles);
				}
				return true;
			}
			case Out:
			{
				const QString v = value.toString();
				if (v != t.out)
				{
					t.out = v;
					emit dataChanged(index, index, m_stdRoles);
				}
				return true;
			}
			case ResultCode:
			{
				const int v = value.toInt();
				if (v != t.resultCode)
				{
					t.resultCode = v;
					emit dataChanged(index, index, m_stdRoles);
				}
				return true;
			}
			case Result:
			{
				const QString v = value.toString();
				if (v != t.result)
				{
					t.result = v;
					emit dataChanged(index, index, m_stdRoles);
				}
				return true;
			}
			}
		}
	}
	return false;
}

QVariant SrcTable::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			if (section <= columnCount())
			{
				return m_header[section];
			}
		}
		else if (orientation == Qt::Vertical)
		{
			return section;
		}
	}
	return QVariant();
}

QVariant SrcTable::data(const QModelIndex &index, int role) const
{
	if (index.isValid() && index.row() < m_data.count())
	{
		const auto &t = m_data[index.row()];
		switch (role)
		{
		case Qt::DisplayRole:
		case Qt::EditRole:
			switch (index.column())
			{
			case Src:
				return t.src;
			case Out:
				return t.out;
			case ResultCode:
				return t.resultCode;
			case Result:
				return t.result;
			}
			break;
		}
	}
	return QVariant();
}

bool SrcTable::insertRows(int row, int count, const QModelIndex &parent)
{
	row = qBound(0, row, rowCount());
	SpinSrc dummy;
	beginInsertRows(parent, row, row + count - 1);
	m_data.insert(row, dummy);
	endInsertRows();
	return true;
}

bool SrcTable::removeRows(int row, int count, const QModelIndex &parent)
{
	row = qBound(0, row, rowCount());
	beginRemoveRows(parent, row, row + count - 1);
	for (int i = 0; i < count; ++i)
	{
		m_data.removeAt(row);
	}
	endRemoveRows();
	return true;
}

QDebug operator<<(QDebug dbg, const SpinSrc &d)
{	return dbg
		<< " SpinSrc["
		<< d.src << ','
		<< d.out << ','
		<< d.resultCode << ','
		<< d.result
		<< "]";
}


void SrcTable::saveConf(QSettings *setting) const
{
	setting->beginGroup("SrcTable");
	setting->beginWriteArray("data", rowCount());
	for (int row = 0; row < rowCount(); ++row)
	{
		setting->setArrayIndex(row);
		setting->setValue("src", m_data[row].src);
		setting->setValue("out", m_data[row].out);
		setting->setValue("resultCode", m_data[row].resultCode);
		setting->setValue("result", m_data[row].result);
	}
	setting->endArray();
	setting->endGroup();
}

void SrcTable::loadConf(QSettings *setting)
{
	beginResetModel();
	setting->beginGroup("SrcTable");
	int n = setting->beginReadArray("data");
	m_data.clear();
	for (int i = 0; i < n; ++i)
	{
		SpinSrc d;
		setting->setArrayIndex(i);
		d.src = setting->value("src").toString();
		d.out = setting->value("out").toString();
		d.resultCode = setting->value("resultCode").toInt();
		d.result = setting->value("result").toString();
		m_data.append(d);
	}
	setting->endArray();
	setting->endGroup();
	endResetModel();
}
