use Env;
use Cwd;



open(USERCONFIG,$ARGV[0]);
while(<USERCONFIG>)
{
  chomp;
  s/#.*//;                # no comments
  s/^\s+//;               # no leading white
  s/\s+$//;               # no trailing white
  my($var,$value) = split(/\s*=\s*/, $_, 2);
  $User_Preferences{$var} = $value;
}

$LISTFile    = $User_Preferences{"LISTFile"};
$OUTPUTDir   = $User_Preferences{"OUTPUTDir"};

$ISLxplus   = $User_Preferences{"ISLxplus"};
$ISHercules = $User_Preferences{"ISHercules"};

$ABSMAT     = $User_Preferences{"ABSMAT"};
$WFRAC      = $User_Preferences{"WFRAC"};
$FIBMAT     = $User_Preferences{"FIBMAT"};
$FIBRAD     = $User_Preferences{"FIBRAD"};
$FIBDIST    = $User_Preferences{"FIBDIST"};
$FIBLENGTH  = $User_Preferences{"FIBLENGTH"};

if( $WFRAC == -1 )
{
    $WFRAC = $ARGV[2];
}

$label2 = "absMat".$ABSMAT."-".$WFRAC."_fibMat".$FIBMAT."_fibRad".$FIBRAD."_fibDist".$FIBDIST;



$CURRENTDir = getcwd();

$OUTPUTDir = $OUTPUTDir."/".$label2;

$OUTPUTJobDir = "";
if( $ISLxplus )
{
    $OUTPUTJobDir = $CURRENTDir."/jobs/".$label2;
  if( ! -e $OUTPUTJobDir )
  {
      system("mkdir ".$OUTPUTJobDir);
  }
}
if( $ISHercules )
{
    $OUTPUTJobDir = $OUTPUTDir;
}



open(LIST,$LISTFile);
while(<LIST>)
{
  chomp;
  s/#.*//;                # no comments
  s/^\s+//;               # no leading white
  s/\s+$//;               # no trailing white
  
  ($label,$particle,$energy,$Nevts,$Njobs,$Nfirst) = split(" ");

  if( $label eq "" )
  {
      next;
  }

  print($label."_".$label2." ".$particle," ".$energy." ".$Nevts." ".$Njobs." ".$Nfirst."\n");
  
  
  
  $runDir = $OUTPUTJobDir."/run_".$label."/";
  $command = "hadd -f ".$runDir."/out.root ";
  
  for($iJob = $Nfirst; $iJob < $Nfirst+$Njobs; ++$iJob)
  {
    $jobDir = $runDir."/job_".$iJob."/";
    if( ! -e $jobDir )
    {
      print("job directory ".$jobDir." doesn't exist. Exiting...\n");
      exit;
    }
    else
    {
      $command = $command." ".$jobDir."/out_".$iJob.".root";
    }
  }
  
  #print($command."\n");
  system($command);
}
