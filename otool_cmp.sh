./ft_otool $@ > tmp_1
otool $@ > tmp_2
diff tmp_1 tmp_2
rm tmp_1 tmp_2
