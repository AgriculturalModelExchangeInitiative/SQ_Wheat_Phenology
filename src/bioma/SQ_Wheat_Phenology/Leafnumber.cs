
using System;
using System.Collections.Generic;
using System.Linq;
using System.Xml;
using CRA.ModelLayer.MetadataTypes;
using CRA.ModelLayer.Core;
using CRA.ModelLayer.Strategy;
using System.Reflection;
using VarInfo=CRA.ModelLayer.Core.VarInfo;
using Preconditions=CRA.ModelLayer.Core.Preconditions;
using CRA.AgroManagement;       
using Phenology.DomainClass;
namespace Phenology.Strategies
{
    public class LeafNumber : IStrategyPhenology
    {
        public LeafNumber()
        {
            ModellingOptions mo0_0 = new ModellingOptions();
            //Parameters
            List<VarInfo> _parameters0_0 = new List<VarInfo>();
            mo0_0.Parameters=_parameters0_0;

            //Inputs
            List<PropertyDescription> _inputs0_0 = new List<PropertyDescription>();
            PropertyDescription pd1 = new PropertyDescription();
            pd1.DomainClassType = typeof(Phenology.DomainClass.PhenologyAuxiliary);
            pd1.PropertyName = "deltaTT";
            pd1.PropertyType = (Phenology.DomainClass.PhenologyAuxiliaryVarInfo.deltaTT).ValueType.TypeForCurrentValue;
            pd1.PropertyVarInfo =(Phenology.DomainClass.PhenologyAuxiliaryVarInfo.deltaTT);
            _inputs0_0.Add(pd1);
            PropertyDescription pd2 = new PropertyDescription();
            pd2.DomainClassType = typeof(Phenology.DomainClass.PhenologyState);
            pd2.PropertyName = "phyllochron";
            pd2.PropertyType = (Phenology.DomainClass.PhenologyStateVarInfo.phyllochron).ValueType.TypeForCurrentValue;
            pd2.PropertyVarInfo =(Phenology.DomainClass.PhenologyStateVarInfo.phyllochron);
            _inputs0_0.Add(pd2);
            PropertyDescription pd3 = new PropertyDescription();
            pd3.DomainClassType = typeof(Phenology.DomainClass.PhenologyState);
            pd3.PropertyName = "hasFlagLeafLiguleAppeared";
            pd3.PropertyType = (Phenology.DomainClass.PhenologyStateVarInfo.hasFlagLeafLiguleAppeared).ValueType.TypeForCurrentValue;
            pd3.PropertyVarInfo =(Phenology.DomainClass.PhenologyStateVarInfo.hasFlagLeafLiguleAppeared);
            _inputs0_0.Add(pd3);
            PropertyDescription pd4 = new PropertyDescription();
            pd4.DomainClassType = typeof(Phenology.DomainClass.PhenologyState);
            pd4.PropertyName = "leafNumber";
            pd4.PropertyType = (Phenology.DomainClass.PhenologyStateVarInfo.leafNumber).ValueType.TypeForCurrentValue;
            pd4.PropertyVarInfo =(Phenology.DomainClass.PhenologyStateVarInfo.leafNumber);
            _inputs0_0.Add(pd4);
            PropertyDescription pd5 = new PropertyDescription();
            pd5.DomainClassType = typeof(Phenology.DomainClass.PhenologyState);
            pd5.PropertyName = "phase";
            pd5.PropertyType = (Phenology.DomainClass.PhenologyStateVarInfo.phase).ValueType.TypeForCurrentValue;
            pd5.PropertyVarInfo =(Phenology.DomainClass.PhenologyStateVarInfo.phase);
            _inputs0_0.Add(pd5);
            mo0_0.Inputs=_inputs0_0;

            //Outputs
            List<PropertyDescription> _outputs0_0 = new List<PropertyDescription>();
            PropertyDescription pd6 = new PropertyDescription();
            pd6.DomainClassType = typeof(Phenology.DomainClass.PhenologyState);
            pd6.PropertyName = "leafNumber";
            pd6.PropertyType = (Phenology.DomainClass.PhenologyStateVarInfo.leafNumber).ValueType.TypeForCurrentValue;
            pd6.PropertyVarInfo =(Phenology.DomainClass.PhenologyStateVarInfo.leafNumber);
            _outputs0_0.Add(pd6);
            mo0_0.Outputs=_outputs0_0;
            //Associated strategies
            List<string> lAssStrat0_0 = new List<string>();
            mo0_0.AssociatedStrategies = lAssStrat0_0;
            //Adding the modeling options to the modeling options manager
            _modellingOptionsManager = new ModellingOptionsManager(mo0_0);
            SetStaticParametersVarInfoDefinitions();
            SetPublisherData();

        }

        public string Description
        {
            get { return "calculate leaf number. LeafNumber increase is caped at one more leaf per day" ;}
        }

        public string URL
        {
            get { return "" ;}
        }

        public string Domain
        {
            get { return "";}
        }

        public string ModelType
        {
            get { return "";}
        }

        public bool IsContext
        {
            get { return false;}
        }

        public IList<int> TimeStep
        {
            get
            {
                IList<int> ts = new List<int>();
                return ts;
            }
        }

        private  PublisherData _pd;
        public PublisherData PublisherData
        {
            get { return _pd;} 
        }

        private  void SetPublisherData()
        {
            _pd = new CRA.ModelLayer.MetadataTypes.PublisherData();
            _pd.Add("Creator", "Pierre MARTRE");
            _pd.Add("Date", "");
            _pd.Add("Publisher", "INRA Montpellier");
        }

        private ModellingOptionsManager _modellingOptionsManager;
        public ModellingOptionsManager ModellingOptionsManager
        {
            get { return _modellingOptionsManager; } 
        }

        public IEnumerable<Type> GetStrategyDomainClassesTypes()
        {
            return new List<Type>() {  typeof(Phenology.DomainClass.PhenologyState),  typeof(Phenology.DomainClass.PhenologyState), typeof(Phenology.DomainClass.PhenologyRate), typeof(Phenology.DomainClass.PhenologyAuxiliary), typeof(Phenology.DomainClass.PhenologyExogenous)};
        }

        // Getter and setters for the value of the parameters of the strategy. The actual parameters are stored into the ModelingOptionsManager of the strategy.


        public void SetParametersDefaultValue()
        {
            _modellingOptionsManager.SetParametersDefaultValue();
        }

        private static void SetStaticParametersVarInfoDefinitions()
        {
        }

        public string TestPostConditions(Phenology.DomainClass.PhenologyState s,Phenology.DomainClass.PhenologyState s1,Phenology.DomainClass.PhenologyRate r,Phenology.DomainClass.PhenologyAuxiliary a,Phenology.DomainClass.PhenologyExogenous ex,string callID)
        {
            try
            {
                //Set current values of the outputs to the static VarInfo representing the output properties of the domain classes
                Phenology.DomainClass.PhenologyStateVarInfo.leafNumber.CurrentValue=s.leafNumber;
                ConditionsCollection prc = new ConditionsCollection();
                Preconditions pre = new Preconditions(); 
                RangeBasedCondition r6 = new RangeBasedCondition(Phenology.DomainClass.PhenologyStateVarInfo.leafNumber);
                if(r6.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyStateVarInfo.leafNumber.ValueType)){prc.AddCondition(r6);}
                string postConditionsResult = pre.VerifyPostconditions(prc, callID); if (!string.IsNullOrEmpty(postConditionsResult)) { pre.TestsOut(postConditionsResult, true, "PostConditions errors in strategy " + this.GetType().Name); } return postConditionsResult;
            }
            catch (Exception exception)
            {
                string msg = ".Phenology, " + this.GetType().Name + ": Unhandled exception running post-condition test. ";
                throw new Exception(msg, exception);
            }
        }

        public string TestPreConditions(Phenology.DomainClass.PhenologyState s,Phenology.DomainClass.PhenologyState s1,Phenology.DomainClass.PhenologyRate r,Phenology.DomainClass.PhenologyAuxiliary a,Phenology.DomainClass.PhenologyExogenous ex,string callID)
        {
            try
            {
                //Set current values of the inputs to the static VarInfo representing the inputs properties of the domain classes
                Phenology.DomainClass.PhenologyAuxiliaryVarInfo.deltaTT.CurrentValue=a.deltaTT;
                Phenology.DomainClass.PhenologyStateVarInfo.phyllochron.CurrentValue=s.phyllochron;
                Phenology.DomainClass.PhenologyStateVarInfo.hasFlagLeafLiguleAppeared.CurrentValue=s.hasFlagLeafLiguleAppeared;
                Phenology.DomainClass.PhenologyStateVarInfo.leafNumber.CurrentValue=s.leafNumber;
                Phenology.DomainClass.PhenologyStateVarInfo.phase.CurrentValue=s.phase;
                ConditionsCollection prc = new ConditionsCollection();
                Preconditions pre = new Preconditions(); 
                RangeBasedCondition r1 = new RangeBasedCondition(Phenology.DomainClass.PhenologyAuxiliaryVarInfo.deltaTT);
                if(r1.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyAuxiliaryVarInfo.deltaTT.ValueType)){prc.AddCondition(r1);}
                RangeBasedCondition r2 = new RangeBasedCondition(Phenology.DomainClass.PhenologyStateVarInfo.phyllochron);
                if(r2.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyStateVarInfo.phyllochron.ValueType)){prc.AddCondition(r2);}
                RangeBasedCondition r3 = new RangeBasedCondition(Phenology.DomainClass.PhenologyStateVarInfo.hasFlagLeafLiguleAppeared);
                if(r3.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyStateVarInfo.hasFlagLeafLiguleAppeared.ValueType)){prc.AddCondition(r3);}
                RangeBasedCondition r4 = new RangeBasedCondition(Phenology.DomainClass.PhenologyStateVarInfo.leafNumber);
                if(r4.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyStateVarInfo.leafNumber.ValueType)){prc.AddCondition(r4);}
                RangeBasedCondition r5 = new RangeBasedCondition(Phenology.DomainClass.PhenologyStateVarInfo.phase);
                if(r5.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyStateVarInfo.phase.ValueType)){prc.AddCondition(r5);}
                string preConditionsResult = pre.VerifyPreconditions(prc, callID); if (!string.IsNullOrEmpty(preConditionsResult)) { pre.TestsOut(preConditionsResult, true, "PreConditions errors in strategy " + this.GetType().Name); } return preConditionsResult;
            }
            catch (Exception exception)
            {
                string msg = ".Phenology, " + this.GetType().Name + ": Unhandled exception running pre-condition test. ";
                throw new Exception(msg, exception);
            }
        }

        public void Estimate(Phenology.DomainClass.PhenologyState s,Phenology.DomainClass.PhenologyState s1,Phenology.DomainClass.PhenologyRate r,Phenology.DomainClass.PhenologyAuxiliary a,Phenology.DomainClass.PhenologyExogenous ex)
        {
            try
            {
                CalculateModel(s, s1, r, a, ex);
            }
            catch (Exception exception)
            {
                string msg = "Error in component Phenology, strategy: " + this.GetType().Name + ": Unhandled exception running model. "+exception.GetType().FullName+" - "+exception.Message;
                throw new Exception(msg, exception);
            }
        }

        private void CalculateModel(Phenology.DomainClass.PhenologyState s, Phenology.DomainClass.PhenologyState s1, Phenology.DomainClass.PhenologyRate r, Phenology.DomainClass.PhenologyAuxiliary a, Phenology.DomainClass.PhenologyExogenous ex)
        {
            double deltaTT = a.deltaTT;
            double phyllochron_t1 = s1.phyllochron;
            int hasFlagLeafLiguleAppeared = s.hasFlagLeafLiguleAppeared;
            double leafNumber_t1 = s1.leafNumber;
            double phase = s.phase;
            double leafNumber;
            leafNumber = leafNumber_t1;
            double phyllochron_;
            if (phase >= 1.0d && phase < 4.0d)
            {
                if (hasFlagLeafLiguleAppeared == 0)
                {
                    if (phyllochron_t1 == 0.0d)
                    {
                        phyllochron_ = 0.0000001d;
                    }
                    else
                    {
                        phyllochron_ = phyllochron_t1;
                    }
                    leafNumber = leafNumber_t1 + Math.Min(deltaTT / phyllochron_, 0.999d);
                }
            }
            s.leafNumber= leafNumber;
        }

    }
}