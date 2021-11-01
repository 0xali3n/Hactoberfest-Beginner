
"""
Program where the user informs how much he has in
BR (Real) money and shows the amount converted into:
- Dollar (USD)
- Euro (EUR)
- Pound Sterling (GBP)
- Indian Rupee (INR)
- Australian Dollar (AUD)
- Canadian Dollar (CAD)
- Singapore Dollar (SGD)
- Swiss Franc (CHF)
- New Zealand Dollar (NZD)
- Hong Kong Dollar (HKD)

Considering USD 1.00 = BRL 5.16 on 07.28.2021
Considering EUR 1.00 = R$ 6.10 on 07.28.2021
Considering GBP 1.00 = BRL 7.17 on 07.28.2021
Considering INR 1.00 = R$ 0.069 on 07.28.2021
Considering AUD 1.00 = R$ 3.79 on 07.28.2021
Considering CAD 1.00 = R$4.11 on 07.28.2021
Considering SGD 1.00 = R$ 3.80 on 07.28.2021
Considering CHF 1.00 = R$ 5.66 on 07.28.2021
Considering NZD 1.00 = R$ 3.58 on 07.28.2021
Considering HKD 1.00 = R$0.66 on 07.28.2021

"""

# value informed in Brazilian currency R$
real = float(input('Enter the value R$: '))

# conversion of the day
Dollar = real / 5.16
Euro = real / 6.09
PoundSterling = real / 7.16
IndianRupee = real / 0.069
AustralianDollar = real / 3.79
CanadianDollar = real / 4.11
SingaporeDollar = real / 3.80
FrenchSwiss = real / 5.65
NewZealandDollar = real / 3.58
DollarHongKong = real / 0.66

# convert from BR to dollar
print(' R$ {:.2f} reais was converted to USD {:.2f} dollars ( USD - US Dollar )'.format(real, Dollar))

# convert from BR to Euro
print(' R$ {:.2f} reais was converted, to EUR {:.2f} euros ( EUR )'.format(real, Euro))

# convert from BR to Pound
print(' Converted R$ {:.2f} reais , to GBP {:.2f} pounds ( GBP - Pound Sterling )'.format(real, PoundSterling))

# convert from BR to Indian Rupee
print(' Converted R$ {:.2f} reais , to INR {:.2f} rupee ( INR - Indian Rupee )'.format(real, IndianRupee))

# convert from BR to Australian dollar
print(' Converted R$ {:.2f} reais , to AUD {:.2f} Australian dollar ( AUD - Australian dollar )'.format(real, AustralianDollar))

# convert from BR to Canadian dollar
print(' Converted R$ {:.2f} reais , to CAD {:.2f} Canadian dollar ( CAD - Canadian dollar )'.format(real, CanadianDollar))

# convert from BR to Singapore dollar
print(' Converted R$ {:.2f} reais , to SGD {:.2f} Singapore dollar ( SGD - Singapore dollar )'.format(real, SingaporeDollar))

# convert from BR to Swiss Franc
print(' Converted R$ {:.2f} reais , to CHF {:.2f} Swiss dollar ( CHF - Swiss Franc )'.format(real, FrenchSwiss))

# convert from BR to New Zealand dollar
print(' Converted R$ {:.2f} reais , to NZD {:.2f} New Zealand Dollar ( NZD - New Zealand Dollar )'.format(real, NewZealandDollar))

# convert from BR to Hong Kong Dollar
print(' R$ {:.2f} reais was converted to HKD {:.2f} hong kong dollar ( HKD - hong kong dollar )'.format(real, DollarHongKong))
