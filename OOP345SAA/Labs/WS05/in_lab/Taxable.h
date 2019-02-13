#ifndef _SICT_TAXABLE_H
#define _SICT_TAXABLE_H

namespace sict
{
	class Taxable
	{
		float m_taxRate;
	public:
		Taxable(float prescribedTaxRate)
			: m_taxRate{ prescribedTaxRate }
		{
		}
		float operator()(float price) const
		{
			return (1 + m_taxRate) * price;
		}
	};
}

#endif // !_SICT_TAXABLE_H