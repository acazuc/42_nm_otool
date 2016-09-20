./ft_nm $@ > tmp_1
nm $@ > tmp_2
diff tmp_1 tmp_2
rm tmp_1 tmp_2
