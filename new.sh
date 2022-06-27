last=$(ls -d */ | grep "problem[0-9]\+\/$" | cut -c8- | sed 's|/$||' | sort -n | tail -n1)
next=$((last+1))

cp -r problem$last problem$next && \
rm -r problem$next/build/* && \
echo Created ./problem$next
