struct hochzeitstag {
  int period; char name[23]; char text[666];
};

#define STANDESAMTLICH 0
#define KIRCHLICH 1
#define hochzeitstage_count 35
const char *dates[2][35];
struct hochzeitstag hochzeitstage[35] = {
  {0, "Hochzeitstag","Juhu heute Hochzeitstag"}, // noch text einfügen !!!!
  {1, "Die Papierhochzeit", "Wie jeder wei\xdf" ", ist Papier nicht besonders stabil. So gilt auch die Partnerschaft nach einem Ehejahr noch lange nicht als gefestigt. Sie ist hauchd\xfc" "nn, wie Papier und kann leicht zerrei\xdf" "en. Dennoch haben die Eheleute das erste Ehejahr erfolgreich gemeistert. Das hei\xdf" "t nat\xfc" "rlich nicht, dass es immer ein reines Honigschlecken war. Sicherlich musste das junge Paar schon so manche Klippe umschiffen. Daher sollten Sie auch das erste Ehejubil\xe4" "um nicht ohne Worte unter den Tisch kehren."},
  {2, "Die Baumwollenhochzeit", "Obwohl die Baumwolle ein recht robuster Stoff ist, der sich bei sehr hohen Temperaturen waschen l\xe4" "sst, wird sie mit jeder Reinigung etwas d\xfc" "nner. Um diesen Vergleich nun auf die Baumwollene Hochzeit anzuwenden, hei\xdf" "t das: Die Ehe ist nach zwei gemeinsam verbrachten Jahren sicherlich schon relativ fest. Sie ger\xe4" "t auch durch st\xe4" "rkere Ersch\xfc" "tterungen nicht aus den Fugen."},
  {3, "Die Lederne Hochzeit", "Nach drei Jahren Ehe ist die Beziehung nicht mehr so d\xfc" "nn, wie Papier. Sie wird nicht bei jedem kleinen Problem auf die Zerrei\xdf" "probe gestellt, sondern ist mittlerweile so z\xe4" "h, wie Leder. Allerdings sollten sich die Ehepartner bewusst sein, dass auch eine gefestigte Beziehung gepflegt werden will. Denn, ebenso wie Leder spr\xf6" "de wird, wenn Sie es vernachl\xe4" "ssigen, leidet auch die Ehe, wenn sie nur noch vor sich hinpl\xe4" "tschert."},
  {4, "Die Seiden Hochzeit", "Die Seide gilt als die st\xe4" "rkste Naturfaser \xfc" "berhaupt. Daraus l\xe4" "sst sich schlie\xdf" "en, dass nun, nach vier Jahren des Zusammenlebens auch die Ehe eine gewisse St\xe4" "rke erreicht hat. Au\xdf" "erdem ist die Seide edel und kostbar. Und genau diese Eigenschaften treffen auch auf eine vierj\xe4" "hrige, gl\xfc" "ckliche Ehe zu. Schlie\xdf" "lich ist es heutzutage l\xe4" "ngst keine Selbstverst\xe4" "ndlichkeit, dass eine Ehe l\xe4" "nger als drei Jahre h\xe4" "lt."},
  {5, "Die H\xf6" "lzerne Hochzeit", "Wenn ein Ehepaar 5 Jahre verheiratet ist, dann hat die Ehe Bestand. Sie ist so fest wie Holz und wird deshalb auch als H\xf6" "lzerne Hochzeit bezeichnet. Um dem Jubelpaar eine weiterhin gl\xfc" "ckliche und harmonische Ehe zu w\xfc" "nschen, wird auf Holz geklopft."},
  {6, "Die Zinn Hochzeit", "Wie Zinn sollte auch die Ehe von Zeit zu Zeit ein bisschen aufgeputzt und poliert werden. Das verleiht neuen Glanz und neuen Schwung. Weil Zinn sehr weich und formbar ist, steht es sinnbildlich f\xfc" "r die Formbarkeit der Ehe. Nutzt diesen Tag und probiert etwas Neues aus."},
  {7, "Die Kupferne Hochzeit", "Kupfer ist ein leicht formbares Metall, das nach einigen Jahren Patina ansetzt. Ebenso gilt auch die Ehe nach sieben Jahren noch als leicht formbar. Kein Ehepaar sollte sich jetzt auf seinen Lorbeeren ausruhen. Wenn die Z\xe4" "rtlichkeiten weniger werden und die Streitigkeiten zunehmen, ist das der Anfang vom Ende. Dass eine Ehe in jedem Jahr in die Br\xfc" "che gehen kann, dar\xfc" "ber sollten sich alle Eheleute bewusst sein."},
  {8, "Die Blecherne Hochzeit", "Als Blech wird in der Regel ein d\xfc" "nn gewalztes Metall bezeichnet. Um welche Art von Metall es sich dabei handelt ist nicht bestimmt. Aber durch die Dicke ist festgelegt, dass es sich um ein biegbares Metallst\xfc" "ck handelt. Die Bezeichnung Blecherne Hochzeit hei\xdf" "t also, dass die Ehe des Jubelpaares zwar best\xe4" "ndig ist, sich aber durchaus noch formen l\xe4" "sst. Nach acht Ehejahren haben sich die beiden Partner aneinander gew\xf6" "hnt."},
  {9, "Die Keramikhochzeit", "Als Keramik werden in der Regel gebrannte Gebrauchs- oder Ziergegenst\xe4" "nde bezeichnet. Das hei\xdf" "t, es handelt sich um Produkte, die sich im Rohzustand leicht verformen lassen, aber nach einer gewissen Zeit im Ofen hart und stabil sind. Sicherlich orientiert sich der Name Keramikhochzeit an diesen Eigenschaften des Materials. Denn nach 9 Ehejahren hat die Ehe bereits feste Formen angenommen. Die Gewohnheiten des Partners sind ebenso bekannt, wie seine kleinen Makel."},
  {10, "Die Rosenhochzeit", "Bei vielen Menschen gilt die Rose als die K\xf6" "nigin der Blumen, denn sie ist wundersch\xf6" "n. Gleichzeitig ist sie die Blume der Liebe, weshalb ihr auch das erste Zehnerjubil\xe4" "um der Hochzeitstage gewidmet sein darf. Denn wer seinen 10. Hochzeitstag begeht, liebt sich wirklich. L\xe4" "ngst wurde die rosarote Brille abgelegt. Der Partner wird so gesehen, geliebt und respektiert, wie er ist."},
  {11, "Die Stahlhochzeit", "Hart wie Stahl ist die Bedeutung, die der Ehe nach 11 gemeinsamen Jahren zugeschrieben wird. Sicherlich ist das nicht verkehrt, denn wer elf Ehejahre hinter sich hat, der hat gemeinsam mit seinem Partner schon so manche H\xf6" "hen und Tiefen durchlebt. Dass die Ehe immer noch Bestand hat, ist ein deutliches Zeichen f\xfc" "r ihre H\xe4" "rte."},
  {12, "Die Nickelhchzeit", "Nickel ist ein Metall, das wegen seiner hohen Widerstandsf\xe4" "higkeit gegen\xfc" "ber Luft, Wasser, S\xe4" "uren und Laugen gerne in viel benutzten Gegenst\xe4" "nden zusammen mit anderen Metallen verarbeitet wird. Es gilt als sehr best\xe4" "ndig und so bedeutet die Nickelhochzeit, dass auch die Ehe nach 12 Jahren eine gewisse Best\xe4" "ndigkeit hat. Das Ehepaar kennt sich nach so vielen Jahren in- und auswendig und hat es gelernt, auch den Alltag zu meistern."},
  {13, "Veilchenhochzeit", "Obwohl die meisten Menschen wahrscheinlich wissen, wie ein Veilchen aussieht, haben sie in freier Natur noch keines zu sehen bekommen. Das liegt daran, dass die kleine, blaue Blume, die wir uns so gern im Blumentopf aufs Fensterbrett stellen, eher im Verborgenen bl\xfc" "ht. Sie ist unter B\xfc" "schen oder am Waldrand zu finden. Und weil das Veilchen trotz seiner Sch\xf6" "nheit recht unscheinbar und schlicht ist, steht es sogar in Gedichten als Symbol f\xfc" "r Bescheidenheit."},
  {14, "Elfenbeinhochzeit", "Elfenbein wird aus den Sto\xdf" "z\xe4" "hnen von Nilpferden und Elefanten gewonnen. Damit diese zentnerschweren Tiere sich mit ihren Z\xe4" "hnen bek\xe4" "mpfen und verletzen k\xf6" "nnen, muss das Material sehr hart sein. Wahrscheinlich ist die Bedeutung der Elfenbeinhochzeit genau diesem Umstand zu verdanken. Denn auch eine Ehe, die in 14 Jahren sicher nicht immer nur Zuckerschlecken war, muss sehr hart im Sinne von stark sein, um so lange zu bestehen."},
  {15, "Die Gl\xe4" "serne Hochzeit", "Nach einem lustigen Brauch wird zur Kristallhochzeit der Garten des Paares mit Girlanden aus Glasflaschen geschm\xfc" "ckt. Der Hof vor dem Haus oder der Weg zur Haust\xfc" "re wird ebenfalls gerne mit Flaschen vollgestellt. Wegen dieser Br\xe4" "uche nennt sich in manchen Gegenden der 15. Hochzeitstag Flaschenhochzeit. Welcher Name auch verwendet wird, eines ist allen gemeinsam: das durchsichtige, zerbrechliche Glas."},
  {16, "Die Saphirhochzeit", "Allgemeine Br\xe4" "uche zur Saphirhochzeit gibt es nicht. Weil der 16. Hochzeitstag den Namen eines Edelsteines tr\xe4" "gt, ist es in manchen Kreisen \xfc" "blich, der Ehefrau ein Schmuckst\xfc" "ck mit einem blauen Saphir zu schenken. Das ist aber kein Muss, denn schlie\xdf" "lich z\xe4" "hlt der blaue Saphir zu den teuersten Schmucksteinen und nicht jedermann hat einen wohlgef\xfc" "llten Geldbeutel. Sicher l\xe4" "sst sich der Hochzeitstag auch ohne ein so teures Geschenk geb\xfc" "hrend feiern."},
  {17, "Die Orchideenhochzeit", "Die Orchidee gilt nicht nur als eine sehr wertvolle Bl\xfc" "te, sondern auch als eine Pflanze, die schwer zu pflegen ist. Deswegen hat der Name Orchideenhochzeit wohl zweierlei Bedeutung. Einerseits weist er darauf hin, dass eine Ehe, die 17 Jahre lang gut gegangen ist, als besonders wertvoll betrachtet werden darf. Andererseits macht er gleichzeitig darauf aufmerksam, dass es nicht so einfach ist, den 17. Hochzeitstag zu erreichen. Denn nur wer seine Liebe pflegt, den Partne  respektiert und sich in Notlagen unterst\xfc" "tzt, kann die Orchideenhochzeit feiern."},
  {18, "Die T\xfc" "rkishochzeit", "Ebenso, wie der T\xfc" "rkis ein wertvolles Mineral ist, darf auch der 18. Hochzeitstag als selten und wertvoll angesehen werden. Schlie\xdf" "lich gibt es nicht viele Ehepaare, die diesen Hochzeitstag miteinander verbringen d\xfc" "rfen. Besondere Br\xe4" "uche gibt es f\xfc" "r die T\xfc" "rkishochzeit nicht. Ein Geschenk, von Verwandten oder Freunden, das zeigt, dass sie an das Jubelpaar denken, wird aber gerne angenommen."},
  {19, "Die Perlmutthochzeit", "Ebenso wie das harte Perlmutt einige Jahre braucht, um seine Widerstandsf\xe4" "higkeit zu erreichen, hat auch die 19–j\xe4" "hrige Ehe einige Zeit ben\xf6" "tigt, um ihre jetzige Stabilit\xe4" "t zu erreichen. Nach fast einem f\xfc" "nftel Jahrhundert ist die Partnerschaft so fest wie Perlmutt. Die Eheleute verstehen sich ohne Worte und wissen genau, um die Freuden und Leiden des Partners bescheid."},
  {20, "Die Porzellan Hochzeit", "Weil gutes Porzellan teuer und edel ist, wurde es schon fr\xfc" "her als \"das Gold in Wei\xdf" "\" bezeichnet. Und genau aus diesen Eigenschaften heraus l\xe4" "sst sich auch der Name f\xfc" "r das 20. Hochzeitsjubil\xe4" "um ableiten. Denn schlie\xdf" "lich darf eine Ehe, in der sich die Partner bereits seit 20 Jahren treu zur Seite stehen, ebenfalls als teuer und kostbar angesehen werden. Nicht viele Paare erreichen dieses Hochzeitsjubil\xe4" "um."},
  {21, "Die Opal Hochzeit", "Dass eine Ehe l\xe4" "nger als 20 Jahre h\xe4" "lt, ist keine Selbstverst\xe4" "ndlichkeit. Im Gegenteil, eine so lange andauernde Beziehung muss als etwas besonders Wertvolles und Au\xdf" "ergew\xf6" "hnliches betrachtet werden. Sie ist sicherlich ebenso kostbar, wie ein Opal. Althergebrachte Br\xe4" "uche gibt es zu diesem Jubil\xe4" "um nicht und auch beim Schm\xfc" "cken des Festtisches und des Festraumes kann man seiner Fantasie freien Lauf lassen."},
  {22, "Die Bronze Hochzeit", "Aus Bronze werden beispielsweise Wandteller gefertigt, die mit einer h\xfc" "bschen Widmung versehen werden k\xf6" "nnen. Aber auch kleine Bronzeskulpturen f\xfc" "r die Vitrine oder die Fensterbank eignen sich als Mitbringsel zum 22. Hochzeitstag. Wer sein Geschenk mit einer lustigen Rede an den Mann und die Frau bringen m\xf6" "chte, verschenkt eine Bronzemedaille und macht eine Anspielung auf die zu erwartende Silberhochzeit und die ebenfalls noch bevorstehende Goldene Hochzeit."},
  {23, "Die Titan Hochzeit", "Ob sich der Name Titanhochzeit f\xfc" "r den 23. Hochzeitstag von dem gleichnamigen Metall ableiten l\xe4" "sst, oder ob es eher auf das G\xf6" "ttergeschlecht aus der griechischen Mythologie zur\xfc" "ckzuf\xfc" "hren ist, l\xe4" "sst sich heute nicht mehr kl\xe4" "ren. Da die Ehe nach 23 Jahren einen beinahe g\xf6" "ttlichen Status erreicht hat, und somit ebenso best\xe4" "ndig ist, wie Titan, klingen beide Erkl\xe4" "rungen einleuchtend."},
  {24, "Die Satin Hochzeit", "Wie der 24. Hochzeitstag zu der Bezeichnung Satinhochzeit kam, l\xe4" "sst sich heute nicht mehr ganz nachvollziehen. Vielleicht l\xe4" "sst sich mit der Festigkeit des Gewebes ein Bezug zur Festigkeit der Ehe schaffen, die nach 24 Jahren sicherlich schon einige Zerrei\xdf" "proben \xfc" "berstehen musste. Vielleicht gibt der Name aber auch einen Hinweis auf die besondere Pflege, die sowohl der empfindliche Satinstoff verlangt, wie auch eine Ehe, die nach so langer Zeit noch immer gl\xfc" "cklich und best\xe4" "ndig ist."},
  {25, "Die Silberhochzeit", "Eines der wohl wichtigsten Hochzeitstage \xfc" "berhaupt ist die Silberhochzeit. Die Ehe dauert nun schon ein viertel Jahrhundert an. Wie altes Silber hat sie ihren bleibenden Wert unter Beweis gestellt. Viele Eheleute feiern diesen Tag geb\xfc" "hrend mit Verwandten, Bekannten und Freunden, die sie in ihrer bisher 25-j\xe4" "hrigen Ehe begleitet haben."},
  {30, "Die Perlenhochzeit", "Die Perlen, die auf der Perlenkette aneinandergereiht sind, stehen symbolisch f\xfc" "r die vielen sich aneinanderreihenden Tage der Ehe. Jede Perle soll an ein Erlebnis der gemeinsam verbrachten 30 Ehejahre erinnern. Die Bedeutung der sich aneinanderreihenden Perlen weist also einerseits auf die L\xe4" "nge hin, die die Beziehung nun bereits \xfc" "berstanden hat. Und sie zeigt gleichzeitig, dass es sich um eine sehr wertvolle Partnerschaft handelt. So wertvoll wie Perlen."},
  {35, "Die Leinen Hochzeit", "Wie auch alle anderen Bezeichnungen der Hochzeitstage stammt der Name Leinwandhochzeit aus fr\xfc" "heren Zeiten. Er ist entstanden, als es die Fotografie noch nicht gab. Denn damals lie\xdf" "en sich die Jubelpaare als Andenken an ihren 35. Hochzeitstag auf Leinwand malen. Die Leinwand wurde gew\xe4" "hlt, weil sie aus Leinen bestand und Leinen, beziehungsweise Linnen, ein fester und extrem rei\xdf" "fester Stoff ist. Trotz seiner Robustheit ist Leinen flexibel und l\xe4" "sst sich daher mit seinen typischen Eigenschaften hervorragend als Symbol f\xfc" "r eine so lange bestehende Lebensgemeinschaft verwenden."},
  {40, "Die Rubin Hochzeit", "Der Edelstein Rubin, als Namensgeber, wird als Stein des Lebens und der Liebe bezeichnet. Man sagt ihm nach, dass er die Kr\xe4" "fte aller anderen Edelsteine vereint.\nRot steht dabei f\xfc" "r das Feuer der Liebe, das auch nach 40 Ehejahren noch immer leuchtet. Traditionell wird am Tag der Rubinhochzeit der Ehering der Frau mit einem roten Rubin veredelt."},
  {45, "Die Messinghochzeit", "ie Bedeutung dieses Tages leitet sich von den Eigenschaften des Metalls ab. Messing ist schwer, extrem haltbar, aber dennoch dehnbar.\nGenauso verh\xe4" "lt es sich auch mit der Ehe nach 45 Jahren. Sie wiegt schwer und ist doch noch flexibel. Und nach 45 Jahren weit sie auch eine gewisse Haltbarkeit auf, viele Paar werden sich jetzt nicht mehr trennen, egal was jetzt noch kommen mag."},
  {50, "Die Goldene Hochzeit", "Wow, 50 Jahre verheiratet, ein halbes Jahrhundert Ehemann und Ehefrau. Was liegt da n\xe4" "her als dieses Jubil\xe4" "um mit einem der edelsten Metalle der Welt zu feiern. Viele Paare erneuern nach 50 Jahren ihr Ehegel\xf6" "bnis in der Kirche und feiern gemeinsam mit Verwandten, Bekannten und Freunden.\nDa sich die meisten Jubilare bei ihrer Goldenen Hochzeit schon in gehobenen Alter befinden, wird das Fest meist von den Kindern und Enkeln ausgerichtet. Die Jubilare d\xfc" "rfen sich dabei ihre Tr\xe4" "ume, die bei Ihrer Hochzeitsfeier zu kurz kamen, erf\xfc" "llen. Damit ist die Goldene Hochzeit einer der wichtigsten Hochzeitstage. Ein wundervolles Geschenk ist ein Zweitring zur Ehe."},
  {55, "Die Juwelenhochzeit", "Am 55. Hochzeitstag wird die Juwelenhochzeit gefeiert. Als Juwelen werden geschliffene Edelsteine bezeichnet. Auch die Ehe hat sich im Laufe der Jahre abgeschliffen. Ecken und Kanten sind poliert. Jetzt zeigt die Ehe, wie die Steine, ihre Kraft und Reinheit. Ein Juwel ist etwas wertvolles. Er ist wertbest\xe4" "ndig und nahezu unzerst\xf6" "rbar. Ebenso wie die Ehe, die mehr als ein halbes Jahrhundert \xfc" "berstanden hat."},
  {60, "Die Diamanthochzeit", "Die Diamantene Hochzeit ist ein ganz besonderes und au\xdf" "ergew\xf6" "hnliches Jubil\xe4" "um. Diamantene Hochzeit, das bedeutet 60 Jahre Ehe. 60 Jahre, in denen Kinder, Enkelkinder und Urenkelkinder geboren und H\xf6" "hen und Tiefen bew\xe4" "ltigt wurden. Bedingungslose Liebe, Treue und Zusammenhalt sind die Faktoren, die eine solch lange Ehe erst erm\xf6" "glichen."},
  {65, "Die Eiserne Hochzeit", "Genau wie das Eisen h\xe4" "lt die Ehe nach 65 Jaher zahlreichen Angriffen stand, ohne an Substanz zu verlieren. Das Ehepaar hat gute und schlechte Zeiten durchstanden, den Kampf gegen Krankheiten aufgenommen und Bew\xe4" "hrungsproben \xfc" "berstanden."},
  {70, "Die Gnadenhochzeit", "Warum sich dieser Hochzeitstag \"Gnadenhochzeit\" nennt, ist nicht \xfc" "berliefert. Auf jeden Fall ist es einer der ganz besonderen Hochzeitstage. Vielleicht, weil nach so langer Zeit nicht nur die Ehe in die Jahre gekommen ist, sondern auch das Ehepaar? Der Begriff Gnade wird fast ausschlie\xdf" "lich mit dem Christentum und der damit verbundenen Gottesgnade in Verbindung gebracht und bedeutet hier \"wohlwollend\"."},
};
