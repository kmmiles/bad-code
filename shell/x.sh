#!/bin/sh
# This is a shell archive (produced by GNU sharutils 4.15.2).
# To extract the files from this archive, save it to some FILE, remove
# everything before the '#!/bin/sh' line above, then type 'sh FILE'.
#
lock_dir=_sh181503
# Made on 2021-04-23 17:21 MDT by <kmmiles@ideapad>.
# Source directory was '/home/kmmiles/.local/src/bad-code/shell'.
#
# Existing files will *not* be overwritten, unless '-c' is specified.
#
# This shar contains:
# length mode       name
# ------ ---------- ------------------------------------------
#   1395 -rwxrwxr-x weather
#
MD5SUM=${MD5SUM-md5sum}
f=`${MD5SUM} --version | egrep '^md5sum .*(core|text)utils'`
test -n "${f}" && md5check=true || md5check=false
${md5check} || \
  echo 'Note: not verifying md5sums.  Consider installing GNU coreutils.'
if test "X$1" = "X-c"
then keep_file=''
else keep_file=true
fi
echo=echo
save_IFS="${IFS}"
IFS="${IFS}:"
gettext_dir=
locale_dir=
set_echo=false

for dir in $PATH
do
  if test -f $dir/gettext \
     && ($dir/gettext --version >/dev/null 2>&1)
  then
    case `$dir/gettext --version 2>&1 | sed 1q` in
      *GNU*) gettext_dir=$dir
      set_echo=true
      break ;;
    esac
  fi
done

if ${set_echo}
then
  set_echo=false
  for dir in $PATH
  do
    if test -f $dir/shar \
       && ($dir/shar --print-text-domain-dir >/dev/null 2>&1)
    then
      locale_dir=`$dir/shar --print-text-domain-dir`
      set_echo=true
      break
    fi
  done

  if ${set_echo}
  then
    TEXTDOMAINDIR=$locale_dir
    export TEXTDOMAINDIR
    TEXTDOMAIN=sharutils
    export TEXTDOMAIN
    echo="$gettext_dir/gettext -s"
  fi
fi
IFS="$save_IFS"
if (echo "testing\c"; echo 1,2,3) | grep c >/dev/null
then if (echo -n test; echo 1,2,3) | grep n >/dev/null
     then shar_n= shar_c='
'
     else shar_n=-n shar_c= ; fi
else shar_n= shar_c='\c' ; fi
f=shar-touch.$$
st1=200112312359.59
st2=123123592001.59
st2tr=123123592001.5 # old SysV 14-char limit
st3=1231235901

if   touch -am -t ${st1} ${f} >/dev/null 2>&1 && \
     test ! -f ${st1} && test -f ${f}; then
  shar_touch='touch -am -t $1$2$3$4$5$6.$7 "$8"'

elif touch -am ${st2} ${f} >/dev/null 2>&1 && \
     test ! -f ${st2} && test ! -f ${st2tr} && test -f ${f}; then
  shar_touch='touch -am $3$4$5$6$1$2.$7 "$8"'

elif touch -am ${st3} ${f} >/dev/null 2>&1 && \
     test ! -f ${st3} && test -f ${f}; then
  shar_touch='touch -am $3$4$5$6$2 "$8"'

else
  shar_touch=:
  echo
  ${echo} 'WARNING: not restoring timestamps.  Consider getting and
installing GNU '\''touch'\'', distributed in GNU coreutils...'
  echo
fi
rm -f ${st1} ${st2} ${st2tr} ${st3} ${f}
#
if test ! -d ${lock_dir} ; then :
else ${echo} "lock directory ${lock_dir} exists"
     exit 1
fi
if mkdir ${lock_dir}
then ${echo} "x - created lock directory ${lock_dir}."
else ${echo} "x - failed to create lock directory ${lock_dir}."
     exit 1
fi
# ============= weather ==============
if test -n "${keep_file}" && test -f 'weather'
then
${echo} "x - SKIPPING weather (file already exists)"

else
${echo} "x - extracting weather (text)"
  sed 's/^X//' << 'SHAR_EOF' | uudecode &&
begin 600 weather
M(R$O8FEN+V)A<V@*"B,@9V5T('=E871H97(@=7-I;F<@=S,N;W)G(&AT;6PR
M='AT(&%N9"!G;V]G;&4*=V5A=&AE<B`H*2!["B`@("!L;V-A=&EO;CTB)"AE
M8VAO("(D0"(@?"!S960@)W,O("\E,C`O9R<I(@H@("`@8W5R;"`M<TP@(FAT
M='!S.B\O=W=W+G<S+F]R9R]S97)V:6-E<R]H=&UL,G1X=#]U<FP]:'1T<',E
M,T$E,D8E,D9W=W<N9V]O9VQE+F-O;24R1G-E87)C:"4S1G$E,T1W96%T:&5R
M)3(U,C`D;&]C871I;VXF;F]I;FQI;F5R969S/6]N)FYO;G5M<SUO;B9E;F1R
M969S/6]N(B!\(&=R97`@)\*P0UQ\PK!&)R!\(&-U="`M9C$@+60G?"<@?"!S
M960@)W,O7EL@7'1=*B\O)R!\('1R("?OO[TG("?"L"<@?"!T<B`M9"`G7&XG
M"B`@("!E8VAO"GT*"B,@57-E('=T='(N:6X@=&\@;W5T<'5T('=E871H97(*
M=W1T<B`H*7L*("`@($Q/0T%424]./2(D,2(*("`@($9,3T-!5$E/3CTB)#(B
M"B`@("!C87-E("0Q(&EN"B`@("`@("`@,"HI"B`@("`@("`@("`@(&EF(%L@
M+7H@(B1&3$]#051)3TXB(%T[('1H96X*("`@("`@("`@("`@("`@($9,3T-!
M5$E/3CTB)&QO8V%T:6]N(@H@("`@("`@("`@("!F:0H@("`@("`@("`@("!T
M<'5T(')E<V5T"B`@("`@("`@("`@(&-U<FP@(G=T='(N:6XO)$9,3T-!5$E/
M3C\P(@H@("`@("`@("`@("!,3T-!5$E/3CTB(@H@("`@("`@("`@("!&3$]#
M051)3TX](B(*("`@("`@("`@("`@.SL*("`@("`@("`Q*BD*("`@("`@("`@
M("`@:68@6R`M>B`B)$9,3T-!5$E/3B(@73L@=&AE;@H@("`@("`@("`@("`@
M("`@1DQ/0T%424]./2(D;&]C871I;VXB"B`@("`@("`@("`@(&9I"B`@("`@
M("`@("`@('1P=70@<F5S970*("`@("`@("`@("`@8W5R;"`B=W1T<BYI;B\D
M1DQ/0T%424]./S$B"B`@("`@("`@("`@($Q/0T%424]./2(B"B`@("`@("`@
M("`@($9,3T-!5$E/3CTB(@H@("`@("`@("`@("`[.PH@("`@("`@(#(J*0H@
M("`@("`@("`@("!I9B!;("UZ("(D1DQ/0T%424].(B!=.R!T:&5N"B`@("`@
M("`@("`@("`@("!&3$]#051)3TX](B1L;V-A=&EO;B(*("`@("`@("`@("`@
M9FD*("`@("`@("`@("`@='!U="!R97-E=`H@("`@("`@("`@("!C=7)L(")W
M='1R+FEN+R1&3$]#051)3TX_,B(*("`@("`@("`@("`@3$]#051)3TX](B(*
M("`@("`@("`@("`@1DQ/0T%424]./2(B"B`@("`@("`@("`@(#L["B`@("`@
M("`@*BD*("`@("`@("`@("`@:68@6R`M>B`B)$Q/0T%424].(B!=.R!T:&5N
M"B`@("`@("`@("`@("`@("!,3T-!5$E/3CTB)&QO8V%T:6]N(@H@("`@("`@
M("`@("!F:0H@("`@("`@("`@("!T<'5T(')E<V5T"B`@("`@("`@("`@(&-U
M<FP@(G=T='(N:6XO)$Q/0T%424].(@H@("`@("`@("`@("!,3T-!5$E/3CTB
M(@H@("`@97-A8PI]"@HC=V5A=&AE<B`B<F%M86@B"@IW='1R(")R86UA:"(*
`
end
SHAR_EOF
  (set 20 21 03 19 20 15 13 'weather'
   eval "${shar_touch}") && \
  chmod 0775 'weather'
if test $? -ne 0
then ${echo} "restore of weather failed"
fi
  if ${md5check}
  then (
       ${MD5SUM} -c >/dev/null 2>&1 || ${echo} 'weather': 'MD5 check failed'
       ) << \SHAR_EOF
b78afb81263dcb395ba8c1034c324396  weather
SHAR_EOF

else
test `LC_ALL=C wc -c < 'weather'` -ne 1395 && \
  ${echo} "restoration warning:  size of 'weather' is not 1395"
  fi
fi
if rm -fr ${lock_dir}
then ${echo} "x - removed lock directory ${lock_dir}."
else ${echo} "x - failed to remove lock directory ${lock_dir}."
     exit 1
fi
exit 0
